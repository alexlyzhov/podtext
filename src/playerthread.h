#ifndef PLAYERTHREAD_H
#define PLAYERTHREAD_H

#include <QThread>
#include "mpg123.h"
#include <ao/ao.h>
#include "remotedata.h"

class PlayerThread : public QThread
{
    Q_OBJECT

    RemoteData *remoteData;

    void run();
public:
    PlayerThread(RemoteData *remoteData);
    ~PlayerThread();
};

#endif // PLAYERTHREAD_H
