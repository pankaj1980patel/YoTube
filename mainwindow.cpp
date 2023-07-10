#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    manager = new QNetworkAccessManager();
//    QObject::connect(manager, &QNetworkAccessManager::finished,
//                     this, [=](QNetworkReply *reply) {
//                         if (reply->error()) {
//                             qDebug() << reply->errorString();
//                             return;
//                         }

//                         QString answer = reply->readAll();

//                         qDebug() << answer;
//                     }
//                     );
}


//void MainWindow::on_pushButton_clicked()
//{
//    request.setUrl(QUrl("http://url"));
//    manager->get(request);
//}
MainWindow::~MainWindow()
{
    delete ui;
}

