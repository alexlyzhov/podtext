#include "repo.h"

using namespace std;

Repo::Repo() {
    QFile jsonFile("repo.json"); // should be able to change this in settings
    if (!jsonFile.exists()) {
        qDebug() << "json repo file does not exist";
    }
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = jsonFile.readAll();
    jsonDoc = QJsonDocument::fromJson(jsonData);
}

Repo::~Repo() {

}

vector<string> Repo::getLangs() {
    vector<string> langs;

    QJsonObject jsonObject = jsonDoc.object();
    QStringList langsList = jsonObject.keys();
    foreach(QString str, langsList) {
      langs.push_back(str.toStdString());
    }

    return langs;
}

vector<Source *> Repo::getSources(string lang) {
    vector<Source *> sources;

//    QStringList::const_iterator constIterator;
//    for (constIterator = langs.constBegin(); constIterator != langs.constEnd(); ++constIterator) {
//        qDebug() << (*constIterator); //toStdString()
//    }
    QJsonObject jsonObject = jsonDoc.object();
    // integrate exception handling
    QJsonValue langValue = jsonObject[QString::fromStdString(lang)];
    QJsonArray langArray = langValue.toArray();
    foreach (QJsonValue val, langArray) { // + name!
        QJsonObject obj = val.toObject();
        qDebug() << obj["name"].toString();
        qDebug() << obj["audio"].toString();
        qDebug() << obj["text"].toString();
        Source *source;
        if (obj["type"] == "remote") {
            source = new RemoteSource(obj["name"].toString().toStdString(),
                          obj["audio"].toString().toStdString(),
                          obj["text"].toString().toStdString());
        } else {
            source = new LocalSource(obj["name"].toString().toStdString(),
                          obj["audio"].toString().toStdString(),
                          obj["text"].toString().toStdString());
        }
        sources.push_back(source);
    }

    return sources;
}


