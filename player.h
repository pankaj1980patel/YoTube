#ifndef PLAYER_H
#define PLAYER_H

#include<QObject>
#include<QDebug>
#include<QMediaPlayer>
#include<QUrl>

class Player : QObject
{
    Q_OBJECT
public:
    Player();
    QMediaPlayer player;
    void play();
    void play(QString url);
};

#endif // PLAYER_H
