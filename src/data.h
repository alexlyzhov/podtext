#ifndef DATA_H
#define DATA_H

#include <QByteArray>
#include <string>

class Data
{
    double percentPlayed = 0;
public:
    std::string language;
    std::string name;
    QByteArray audio;
    QByteArray text;

    Data();
    double getPercentPlayed();
};

#endif // DATA_H
