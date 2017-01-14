#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QDebug>
#include "source.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QByteArray>
#include "data.h"

class Downloader : QObject
{
    Q_OBJECT

    Source source;
public:
    QNetworkAccessManager *manager = nullptr;
    QNetworkReply *audioReply = nullptr;
    QNetworkReply *textReply = nullptr;
    Data *data = nullptr;

    Downloader(Source source);
    virtual ~Downloader();
//    static size_t WriteAudio(void *contents, size_t size, size_t nmemb, void *userp);
    Data *download();

public slots:
    void replyFinished(QNetworkReply *);
    void getAudioChunk();
    void onError(QNetworkReply::NetworkError code);
    void downloadProgress(qint64 received, qint64 total);

//signals:
//    void downloaded();
};

#endif // DOWNLOADER_H
