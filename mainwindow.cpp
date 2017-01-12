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
    qDebug() << "enablePlayer()";

    Source source("http://www.slow-chinese.com/podcasts/Slow_Chinese_150.mp3",
                  "http://www.slow-chinese.com/podcast/150-e-gao-de-chi-du/");
    downloader = new Downloader(source);
    Data *data = downloader->download();

    PlayerWidget *playerWidget = new PlayerWidget(this);
    setCentralWidget(playerWidget);
}
