#include "listwidget.h"
#include "mainwindow.h"

ListWidget::ListWidget(MainWindow *parent)
{
    this->mainWindow = parent;
    qDebug() << "right constructor";

    QPushButton *button = new QPushButton("&Download");
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);

    setLayout(layout);
}

void ListWidget::buttonClicked() {
    mainWindow->enablePlayer();
}
