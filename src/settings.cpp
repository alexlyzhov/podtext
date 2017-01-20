#include "settings.h"

using namespace std;

Settings::Settings(string filename) {
    // so far it's only reading settings, it should also be able to write them to the settings json file
    QFile jsonFile(QString::fromStdString(filename)); // should be able to change this in settings
    if (!jsonFile.exists()) {
        qDebug() << "json settings file does not exist";
    }
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = jsonFile.readAll();
    jsonDoc = QJsonDocument::fromJson(jsonData);
}

vector<string> Settings::getSettings() {
    vector<string> results;

    QJsonObject obj = jsonDoc.object();
    // integrate exception handling

    QStringList keys = obj.keys();
    foreach(QString str, keys) {
        results.push_back(str.toStdString());
    }

    return results;
}

string Settings::getSetting(string name) {
    QJsonObject jsonObject = jsonDoc.object();
    QString result = jsonObject[QString::fromStdString(name)].toString();
    return result.toStdString();
}
