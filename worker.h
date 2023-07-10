#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class Worker : public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager manager;
public:
    explicit Worker(QObject *parent = nullptr);

signals:

public slots:
    void get(QString location);

private slots:
    void readyRead();
    void finished(QNetworkReply *reply);
};

#endif // WORKER_H
