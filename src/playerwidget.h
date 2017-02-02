#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QDebug>
#include "data.h"
#include <QMediaPlayer>
#include <QBuffer>
#include "textview.h"
#include <QLineEdit>
#include <QScrollArea>
#include <QFrame>
#include "playerthread.h"

class MainWindow;

class PlayerWidget : public QWidget
{
    Q_OBJECT

    QMediaPlayer *player;
    QBuffer *buffer;
    bool playing = false;
public:
    MainWindow *mainWindow;
    Data *data;

    explicit PlayerWidget(MainWindow *parent, Data *data);
    void updateStatus();
    void play();
    ~PlayerWidget();

signals:

public slots:
};

#endif // PLAYERWIDGET_H
