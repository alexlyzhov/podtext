#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <string>
#include <iostream>
#include <fstream>
#include <QDebug> //remove all this stuff
#include "downloader.h"
#include "listwidget.h"
#include "playerwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    Downloader *downloader;
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    void enablePlayer();

signals:

};

#endif // MAINWINDOW_H
