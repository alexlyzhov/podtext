#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>
#include <fstream>
#include <QtGui>
#include <QApplication>
#include <QWidget>
#include "mainwindow.h"

using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    //

    MainWindow window;
    window.show();

    return app.exec();
}
