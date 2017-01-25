#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QDebug>
#include "source.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QByteArray>
#include "remotesource.h"
#include "remotedata.h"
#include "datacreator.h"

class MainWindow;

class Downloader : QObject, public DataCreator
{
    Q_OBJECT

    MainWindow *mainWindow;
    RemoteSource *remoteSource;
    QNetworkAccessManager *manager = nullptr;
    QNetworkReply *audioReply = nullptr;
    QNetworkReply *textReply = nullptr;
    QNetworkReply *currentReply = nullptr;
    RemoteData *data = nullptr;
public:

    Downloader(MainWindow *mainWindow, RemoteSource *remoteSource);
    virtual ~Downloader();
    RemoteData *getData();
    void downloadText();
    void downloadAudio();

public slots:
    void readTextChunk();
    void readAudioChunk();
    void textFinished();
    void audioFinished();
    void onError(QNetworkReply::NetworkError code);
//    void downloadProgress(qint64 received, qint64 total);
};

#endif // DOWNLOADER_H
