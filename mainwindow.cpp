#include "mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QPushButton *quitButton = new QPushButton("&Quit");
    QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(mySlot()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quitButton);

    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    setCentralWidget(widget);
    show();

    resize(320, 240);
    setWindowTitle(QApplication::translate("toplevel", "Top-level widget"));
}


void MainWindow::mySlot() {
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel* label = new QLabel("QLabel With Red Text");
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    Source source("http://www.slow-chinese.com/podcasts/Slow_Chinese_150.mp3");
    Downloader downloader(source);
    downloader.download();

    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    setCentralWidget(widget);
}

