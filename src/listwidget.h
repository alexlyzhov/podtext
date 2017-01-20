#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include "repo.h"
#include "settings.h"

class MainWindow;

class ListWidget : public QWidget
{
    Q_OBJECT
public:
    Repo *repo;
    Settings *settings;

    MainWindow *mainWindow;
    ListWidget(MainWindow *parent, Repo *repo, Settings *settings);

signals:

public slots:
    void buttonClicked();
};

#endif // LISTWIDGET_H
