#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include <QDebug>
#include <string>

using namespace std;

class Parser
{
    string text;
public:
    Parser(QString text);
    QString parse();
};

#endif // PARSER_H
