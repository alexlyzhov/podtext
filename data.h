#ifndef DATA_H
#define DATA_H

#include <QByteArray>

class Data
{
public:
    QByteArray audio;
    QByteArray text;
    double percentDownloaded = 0;
    double percentPlayed = 0;

    Data();
};

#endif // DATA_H
