#ifndef REPO_H
#define REPO_H

#include <string>
#include <vector>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QDebug>
#include <QString>
#include "source.h"
#include "remotesource.h"
#include "localsource.h"

using namespace std;

class Repo
{
private:
    QJsonDocument jsonDoc;
public:
    Repo(string filename);
    virtual ~Repo();
    vector<string> getLangs();
    vector<Source *> getSources(string lang);
};

#endif // REPO_H
