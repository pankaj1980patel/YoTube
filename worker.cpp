#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject(parent)
{

}

void Worker::get(QString location)
{
    qInfo() << "Getting info from server";
    QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(location)));
    qInfo()<<reply->readAll();
    qInfo()<<"---------------------------------------";
    connect(reply,&QNetworkReply::readyRead,this,&Worker::readyRead);
//    connect(reply, &QNetworkReply::readyRead, this, &worker::readyRead);
//    connect(reply, &QNetworkReply::finished, this, &worker::finished);
}

void Worker::readyRead()
{
    qInfo() << "ReadyRead";
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if(reply) qInfo() << reply->readAll();

//    qInfo() << "Ready read";
//    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
//    if (reply)
//    {
//        qInfo() << reply->readAll();
//    }
}

void Worker::finished(QNetworkReply *reply)
{
//    Q_UNUSED(reply);
    qInfo() << "finished";
    reply->deleteLater();
//    qInfo() << "Inside finished";
//    reply->deleteLater();
//    qInfo() << "Finished";
}
