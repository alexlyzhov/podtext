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

//    onError("Yerror");

//    resize(320, 240);
//    setWindowTitle(QApplication::translate("toplevel", "Top-level widget"));
}


void MainWindow::enablePlayer(Data *data) {
    // it can be called twice due to synchronization issues, therefore nullptr check
    widgetNum = 1;
    if (playerWidget == nullptr) {
        qDebug() << "MainWindow::enablePlayer()";
        playerWidget = new PlayerWidget(this, data);
        listWidget->setParent(0);
        setCentralWidget(playerWidget); // reparent previous widget to avoid losing it
    } else {
        qDebug() << "MainWindow::enablePlayer is getting called again";
    }
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
    if (listWidget != nullptr) {
        listWidget->updateStatus();
    }
    if (playerWidget != nullptr) {
        playerWidget->updateStatus();
    }
}

void MainWindow::onError(string str) {
    QMessageBox messageBox;
    messageBox.critical(0, "Error", str.c_str());
    messageBox.setStandardButtons(QMessageBox::Ok);
    connect(messageBox.button( QMessageBox::Ok ), SIGNAL(clicked()), qApp, SLOT(quit()) );
    messageBox.exec();
}
