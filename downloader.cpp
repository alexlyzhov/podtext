#include "downloader.h"

using namespace std;

Downloader::Downloader(Source source) : source(source)
{
    this->source = source;
}

Downloader::~Downloader() {

}

Data *Downloader::download() {
    data = new Data();

    manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
    QNetworkRequest audioRequest(QUrl(source.getAudioUrl().c_str()));
    audioRequest.setRawHeader("User-Agent" , "Mozilla Firefox"); //needed for the server to accept the request otherwise error ensues
    audioReply = manager->get(audioRequest);
//    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl("http://qt-project.org")));
//    qDebug() << "got reply in download()";
//    qDebug() << "isRunning: " << reply->isRunning();
//    qDebug() << "isFinished: " << reply->isFinished();
//    qDebug() << "isError: " << reply->error();
//    qDebug() << "errorString: " << reply->errorString();
    connect(audioReply, SIGNAL(readyRead()), this, SLOT(getAudioChunk()));
//    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
//    connect(reply, SIGNAL(finished()), SLOT(specReplyFinished()));
    connect(audioReply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(onError(QNetworkReply::NetworkError)));

    QNetworkRequest textRequest(QUrl(source.getTextUrl().c_str()));
    textRequest.setRawHeader("User-Agent" , "Mozilla Firefox"); //needed for the server to accept the request otherwise error ensues
    textReply = manager->get(textRequest);
    connect(audioReply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(onError(QNetworkReply::NetworkError)));

    return data;
}

void Downloader::replyFinished(QNetworkReply *reply) {
//    qDebug() << "reply finished";
//    qDebug() << "isRunning: " << reply->isRunning();
//    qDebug() << "isFinished: " << reply->isFinished();
//    qDebug() << "isError: " << reply->error();
//    qDebug() << "errorString: " << reply->errorString();

//    QByteArray data = reply->readAll();
//    qDebug() << "data was read:";
//    qDebug() << data.size();

    if (reply == textReply) {
        this->data->text = reply->readAll();
    }

    qDebug() << "all the data of one request was read";
    qDebug() << "audio size in memory: " << this->data->audio.size();
    qDebug() << "text size in memory: " << this->data->text.size();
    reply->deleteLater();
}

void Downloader::onError(QNetworkReply::NetworkError code)
{
    qDebug() << "Request failed with code " << code;
}

void Downloader::downloadProgress(qint64 received, qint64 total) {
    qDebug() << "received " << received << " total " << total;
}

void Downloader::getAudioChunk() {
    QByteArray data = audioReply->readAll();
    this->data->audio.append(data);
//    qDebug() << "data chunk was read: " << data.size();
}
