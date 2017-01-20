#include "listwidget.h"
#include "mainwindow.h"

ListWidget::ListWidget(MainWindow *parent, Repo *repo, Settings *settings)
{
    this->mainWindow = parent;
    this->repo = repo;
    this->settings = settings; // write an interface to show and change settings in list widget

    QPushButton *button = new QPushButton("&Download");
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);

    setLayout(layout);
}

void ListWidget::buttonClicked() {
    vector<string> langs = repo->getLangs();
    foreach(string str, langs) {
        qDebug() << str.c_str();
    }

    vector<Source *> sources = repo->getSources("ch");
    Source *source = sources[0];

    Data *data = mainWindow->getData(source);

    mainWindow->enablePlayer(data);
}
