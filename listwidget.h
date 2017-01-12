#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

class MainWindow;

class ListWidget : public QWidget
{
    Q_OBJECT
public:
    MainWindow *mainWindow;
    ListWidget(MainWindow *parent);

signals:

public slots:
    void buttonClicked();
};

#endif // LISTWIDGET_H
