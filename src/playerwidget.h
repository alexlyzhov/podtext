#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QDebug>
#include "data.h"

class MainWindow;

class PlayerWidget : public QWidget
{
    Q_OBJECT
public:
    MainWindow *mainWindow;
    Data *data;

    explicit PlayerWidget(MainWindow *parent, Data *data);
    void updateStatus();

signals:

public slots:
};

#endif // PLAYERWIDGET_H
