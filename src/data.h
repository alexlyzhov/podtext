#ifndef DATA_H
#define DATA_H

#include <QByteArray>

class Data
{
    double percentPlayed = 0;
public:
    QByteArray audio;
    QByteArray text;

    Data();
    double getPercentPlayed();
};

#endif // DATA_H
