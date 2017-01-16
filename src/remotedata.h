#ifndef REMOTEDATA_H
#define REMOTEDATA_H

#include "data.h"

class RemoteData : public Data
{
public:
    double audioDownloadedPercent = 0;
    double textDownloadedPercent = 0;
    RemoteData();
//    double getAudioDownloadedPercent();
//    double getTextDownloadedPercent();
};

#endif // REMOTEDATA_H
