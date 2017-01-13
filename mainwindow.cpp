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
    repo.getLangs();
    vector<Source> chSources = repo.getSources("ch");
    Source mySource = chSources[0];
    downloader = new Downloader(mySource);
    Data *data = downloader->download();

    PlayerWidget *playerWidget = new PlayerWidget(this);
    setCentralWidget(playerWidget);
}
