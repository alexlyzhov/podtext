#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include "repo.h"
#include "settings.h"
#include <QColumnView>
#include "data.h"

class MainWindow;

class ListWidget : public QWidget
{
    Q_OBJECT

    Data *curData = nullptr;
    bool blockButtons = false;
public:
    Repo *repo;
    Settings *settings;
    QColumnView view;

    MainWindow *mainWindow;
    ListWidget(MainWindow *parent, Repo *repo, Settings *settings);
    void updateStatus();

signals:

public slots:
    void buttonClicked();
};

#endif // LISTWIDGET_H
