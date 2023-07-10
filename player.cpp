#include "player.h"

#include <QAudioOutput>
#include <QUrl>

Player::Player()
{

}

void Player::play()
{
//    QAudioOutput  audioOutput;
    QMediaContent media(QUrl("https://rr1---sn-up3vo5-nu8l.googlevideo.com/videoplayback?expire=1688949367&ei=F_6qZKqZD8iTg8UPkcSnyAM&ip=123.136.226.170&id=o-APvefzBpnSb_vDMFsCi9DpyVYFN-LiakQwkPBj6J2Hhn&itag=251&source=youtube&requiressl=yes&mh=jn&mm=31%2C29&mn=sn-up3vo5-nu8l%2Csn-8vq54voxpo-h55e&ms=au%2Crdu&mv=m&mvi=1&pl=24&initcwndbps=885000&spc=Ul2Sq3WydignnfUlFELBPyZmY9gRN5w&vprv=1&svpuc=1&mime=audio%2Fwebm&gir=yes&clen=6278373&dur=544.521&lmt=1598318692846944&mt=1688927352&fvip=7&keepalive=yes&fexp=24007246%2C51000014%2C51000023&beids=24350017&c=ANDROID&txp=6211222&sparams=expire%2Cei%2Cip%2Cid%2Citag%2Csource%2Crequiressl%2Cspc%2Cvprv%2Csvpuc%2Cmime%2Cgir%2Cclen%2Cdur%2Clmt&sig=AOq0QJ8wRQIgTSoUqatBEo76aMKyLzSG-BDimlNccTgTAvFcFecFk9QCIQDGUmyBaukD1nWkV04KR-gSPKz12QmTlZ7Bo7uRyBZU-Q%3D%3D&lsparams=mh%2Cmm%2Cmn%2Cms%2Cmv%2Cmvi%2Cpl%2Cinitcwndbps&lsig=AG3C_xAwRQIhAI4olNZrT4TjxCRv3E_jhUG7M5CSc-g8dWIxPtnmV4dLAiBEobkIAWo0DpTT2JyTvPd4fcvIUeAd_E1XVr8K2QcVvA%3D%3D"));

    player.setMedia(media);
    player.play();


}
void Player::play(QString url)
{
    //    QAudioOutput  audioOutput;
    QUrl ul(url);
    QMediaContent media(ul);

    player.setMedia(media);
    player.play();


}
