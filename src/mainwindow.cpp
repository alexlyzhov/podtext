#include "mainwindow.h"

using namespace std;

MainWindow::~MainWindow() {

}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    string settingsFilename = "settings.json";
    settings = new Settings(settingsFilename);

    vector<string> settingKeys = settings->getSettings();
    foreach(string str, settingKeys) {
        qDebug() << "setting: " << str.c_str();
    }

    string repofile = settings->getSetting("repo filename");
    repo = new Repo(repofile);

    listWidget = new ListWidget(this, repo, settings);
    setCentralWidget(listWidget);

//    resize(320, 240);
//    setWindowTitle(QApplication::translate("toplevel", "Top-level widget"));
}


void MainWindow::enablePlayer(Data *data) {
    playerWidget = new PlayerWidget(this, data);
    setCentralWidget(playerWidget);
}

Data *MainWindow::getData(Source *source) {
    Data *data = nullptr;
    if (source == dynamic_cast<RemoteSource *>(source)) {
        RemoteSource *remoteSource = dynamic_cast<RemoteSource *>(source);
        Downloader *downloader = new Downloader(this, remoteSource);
        data = downloader->getData();
    } else {
        LocalSource *localSource = dynamic_cast<LocalSource *>(source);
        Reader *reader = new Reader(localSource);
        data = reader->getData();
    }
    return data;
}

void MainWindow::updateStatus() {
//    qDebug() << "MainWindow::updateStatus()";
    if (playerWidget != nullptr) {
        playerWidget->updateStatus();
    }
}
