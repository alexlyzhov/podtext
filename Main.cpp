#include <iostream>
#include <string>
#include <curl/curl.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <fstream>
#include <QtGui>
#include <QApplication>
#include <QWidget>
#include "mainwindow.h"
// windows: urlmon.dll, URLDownloadToFile? Or libcurl which could have been easier

using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    MainWindow window;
//    window.show();

    return app.exec();
}

//#include <QtMultimedia>
//#include <QtMultimediaWidgets>
//  QApplication app (argc, argv);

//  QMediaPlayer *player = new QMediaPlayer();
//  player->setMedia(QUrl::fromLocalFile("/home/nikkou/Dropborx/Techno/cpp/project/Slow_Chinese_164.mp3"));
//  player->setVolume(50);
//  player->play();
//  cout << strlen(player->errorString().toLatin1().data()) << "\n";
//  cout << player->error() << "\n";
//  // std::this_thread::sleep_for(std::chrono::milliseconds(20000));
