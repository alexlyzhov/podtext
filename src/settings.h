#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <vector>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QStringList>

using namespace std;

class Settings
{
private:
    QJsonDocument jsonDoc;
public:
    Settings(string filename);
    vector<string> getSettings();
    string getSetting(string name);
};

#endif // SETTINGS_H
