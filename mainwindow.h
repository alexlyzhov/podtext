#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QLabel>
#include <string>
#include <iostream>
#include <fstream>
#include <QDebug> //remove all this stuff
#include "downloader.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:
    void mySlot();
};

#endif // MAINWINDOW_H
