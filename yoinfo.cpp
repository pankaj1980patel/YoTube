#include "yoinfo.h"
#include "player.h"

#include <QFile>



YoInfo::YoInfo()
{

}
QString resolvePlayerResponse(const QString& watchHtml)
{
    if (watchHtml.isEmpty())
        return QString();

    QRegularExpressionMatch match = QRegularExpression("ytInitialPlayerResponse = (.*)}};").match(watchHtml);
    return match.hasMatch() ? match.captured(1) + "}}"
                            : QString();
}


QString resolveM3U8Link(const QString& watchHtml)
{
    if (watchHtml.isEmpty())
        return QString();

    QRegularExpressionMatch match = QRegularExpression("hlsManifestUrl\":\"(.*\\/file\\/index\\.m3u8)").match(watchHtml);
    return match.hasMatch() ? match.captured(1) : QString();
}

QJsonObject YoInfo::getInfo(const QUrl &url, bool throwOnError)
{
    QString videoId = getVideoId(url);
    qInfo()<<"Video Id : " << videoId;
    if (videoId.isEmpty())
        return QJsonObject();

    QUrl ytApi("https://www.youtube.com/watch");
    QUrlQuery ytApiQuery;
    ytApiQuery.addQueryItem("v", videoId);
    ytApi.setQuery(ytApiQuery);
    qInfo()<<"code Reached here";
    QNetworkAccessManager manager;
    QNetworkReply* reply = manager.get(QNetworkRequest(ytApi));
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Error getting YouTube video response:" << reply->errorString();

        if (throwOnError)
            throw std::runtime_error("Cannot get YouTube video response");

        return QJsonObject();
    }
    QString watchHtml = QString::fromUtf8(reply->readAll());
    qInfo()<<watchHtml;
    QString ytInitialPlayerResponse = resolvePlayerResponse(watchHtml);
//    qInfo() << "ytInitialPlayerResponse:" << ytInitialPlayerResponse;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(ytInitialPlayerResponse.toUtf8());

    QFile jsonFile("jsondoc.json");
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(jsonDoc.toJson());
    jsonFile.close();

    QJsonObject playerResponse = jsonDoc.object();
    QJsonObject streamingData = playerResponse.value("streamingData").toObject();

    QJsonArray formats = streamingData.value("formats").toArray();
    QJsonArray adaptiveFormats = streamingData.value("adaptiveFormats").toArray();
    QJsonValue lastElement = adaptiveFormats.last();
    QMediaPlayer *player= new QMediaPlayer;
    if (lastElement.isObject()) {
        QJsonObject lastObject = lastElement.toObject();
        QString url = lastObject.value("url").toString();

        // Use the URL as needed
        qDebug() << "Last URL:" << url;

        QUrl ul(url);
        QMediaContent media(ul);

        player->setMedia(media);
        player->play();
//        player->~QMediaPlayer();
    } else {
        qDebug() << "Last element is not an object";
    }
//    formats.append(adaptiveFormats);

    return QJsonObject();
}

QString YoInfo::getVideoId(const QUrl &url)
{
    QString urlString = url.toString(QUrl::RemoveFragment | QUrl::RemoveQuery | QUrl::RemoveUserInfo);
    if (urlString.contains("youtu.be/"))
    {
        QString videoId;
        int index = urlString.indexOf("youtu.be/") + 9;
        videoId = urlString.mid(index, 11);
        return videoId;
    }
    else if (urlString.contains("youtube.com/watch"))
    {
        QUrlQuery query(url);
        QString videoId = query.queryItemValue("v");
        return videoId;
    }

    return QString();
}

