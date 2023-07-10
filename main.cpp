#include "mainwindow.h"
#include "worker.h"
#include "yoinfo.h"
#include "player.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Worker work;
//    work.get("https://www.google.com");
    YoInfo yoinfo;
    yoinfo.getInfo(QUrl("https://www.youtube.com/watch?v=QNfdZY91t68"));
//    yoinfo.getInfo(QUrl("https://www.youtube.com/watch?v=bBFaHjyGulE"));

//    Player player;
//    player.play();
    return a.exec();
}
