#ifndef YOINFO_H
#define YOINFO_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QUrlQuery>

#include <QEventLoop>

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
class YoInfo
{
public:
    YoInfo();
    QJsonObject getInfo(const QUrl& url, bool throwOnError = false);
    QString getVideoId(const QUrl& url);
    QString resolveM3U8Link(const QString& watchHtml);
};

#endif // YOINFO_H
