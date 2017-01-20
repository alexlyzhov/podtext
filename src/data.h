#ifndef DATA_H
#define DATA_H

#include <QByteArray>
#include <QString>
#include <string>
#include "parser.h"

class Data
{
    bool textReady;
public:
    std::string language;
    std::string name;
    QByteArray audio;
    QString text;

    Data();
    void parseText();
    bool isTextReady();

};

#endif // DATA_H
