#include "downloader.h"

using namespace std;

Downloader::Downloader(RemoteSource *source_param) : DataCreator(source_param)
{
    remoteSource = static_cast<RemoteSource *>(source);
}

Downloader::~Downloader() {

}

RemoteData *Downloader::getData() {
    data = new RemoteData();

    data->name = remoteSource->getName();
    data->language = remoteSource->getLanguage();

    manager = new QNetworkAccessManager();
//    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

    QNetworkRequest textRequest(QUrl(remoteSource->getTextUrl().c_str()));
    textRequest.setRawHeader("User-Agent" , "Mozilla Firefox"); //needed for the server to accept the request otherwise error ensues
    textReply = manager->get(textRequest);
    connect(textReply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(onError(QNetworkReply::NetworkError)));
    connect(textReply, SIGNAL(readyRead()), this, SLOT(readTextChunk()));
    connect(textReply, SIGNAL(finished()), SLOT(textFinished()));

    QNetworkRequest audioRequest(QUrl(remoteSource->getAudioUrl().c_str()));
    audioRequest.setRawHeader("User-Agent" , "Mozilla Firefox"); //needed for the server to accept the request otherwise error ensues
    audioReply = manager->get(audioRequest);
    connect(audioReply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(onError(QNetworkReply::NetworkError)));
    connect(audioReply, SIGNAL(readyRead()), this, SLOT(readAudioChunk()));
//    connect(audioReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64))); //too slow
    connect(audioReply, SIGNAL(finished()), SLOT(audioFinished()));

    return data;
}

void Downloader::textFinished() {
    qDebug() << "all text was read";
    qDebug() << "text size in memory: " << this->data->text.size();
    textReply->deleteLater();
}

void Downloader::audioFinished() {
    qDebug() << "all audio was read";
    qDebug() << "audio size in memory: " << this->data->audio.size();
    audioReply->deleteLater();
}

void Downloader::onError(QNetworkReply::NetworkError code)
{
    qDebug() << "Request failed with code " << code;
}

//void Downloader::downloadProgress(qint64 received, qint64 total) {
//    qDebug() << "received " << received << " total " << total;
//}

void Downloader::readTextChunk() {
    QByteArray data = textReply->readAll();
    this->data->text.append(data);
    qlonglong totalSize = textReply->header(QNetworkRequest::ContentLengthHeader).toLongLong();
    double size = this->data->text.size();
    this->data->textDownloadedPercent = size / totalSize;
    qDebug() << "text percent" << this->data->textDownloadedPercent;
}

void Downloader::readAudioChunk() {
    QByteArray data = audioReply->readAll();
    this->data->audio.append(data);
    qlonglong totalSize = audioReply->header(QNetworkRequest::ContentLengthHeader).toLongLong();
    double size = this->data->audio.size();
    this->data->audioDownloadedPercent = size / totalSize;
    qDebug() << "audio percent" << this->data->audioDownloadedPercent;
}
