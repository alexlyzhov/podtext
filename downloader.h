#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <curl/curl.h>
#include <QDebug>
#include "source.h"

class Downloader
{
    Source source;
public:
    Downloader(Source source);
    static size_t WriteAudio(void *contents, size_t size, size_t nmemb, void *userp);
    void download();
};

#endif // DOWNLOADER_H
