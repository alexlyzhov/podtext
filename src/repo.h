#ifndef REPO_H
#define REPO_H

#include <string>
#include <vector>
#include "source.h"
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QDebug>

using namespace std;

class Repo
{
private:
    QJsonDocument jsonDoc;
public:
    Repo();
    virtual ~Repo();
    vector<string> getLangs();
    vector<Source> getSources(string lang);
};

#endif // REPO_H
