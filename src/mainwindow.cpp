#include "mainwindow.h"

using namespace std;

MainWindow::~MainWindow() {

}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ListWidget *listWidget = new ListWidget(this);
    setCentralWidget(listWidget);

//    resize(320, 240);
//    setWindowTitle(QApplication::translate("toplevel", "Top-level widget"));
}


void MainWindow::enablePlayer() {
    Repo repo;
    vector<string> langs = repo.getLangs();
    foreach(string str, langs) {
        qDebug() << str.c_str();
    }

    vector<Source *> sources = repo.getSources("ja");
    Source *source = sources[0];
    Data *data = nullptr;
    if (source == dynamic_cast<RemoteSource *>(source)) {
        RemoteSource *remoteSource = dynamic_cast<RemoteSource *>(source);
        Downloader *downloader = new Downloader(remoteSource);
        data = downloader->getData();
    } else {
        LocalSource *localSource = dynamic_cast<LocalSource *>(source);
        Reader *reader = new Reader(localSource);
        data = reader->getData();
    }
//    RemoteSource *mySource = static_cast<RemoteSource *>(source);


    PlayerWidget *playerWidget = new PlayerWidget(this, data);
    setCentralWidget(playerWidget);
}
