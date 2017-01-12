#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>

class MainWindow;

class PlayerWidget : public QWidget
{
    Q_OBJECT
public:
    MainWindow *mainWindow;

    explicit PlayerWidget(MainWindow *parent);

signals:

public slots:
};

#endif // PLAYERWIDGET_H
