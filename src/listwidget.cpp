#include "listwidget.h"
#include "mainwindow.h"

ListWidget::ListWidget(MainWindow *parent, Repo *repo, Settings *settings)
{
    this->mainWindow = parent;
    this->repo = repo;
    this->settings = settings; // write an interface to show and change settings in list widget

//    QColumnView view = new QColumnView();


    QPushButton *button = new QPushButton("&Play");
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);\

    setLayout(layout);
}

void ListWidget::buttonClicked() {
    if (!blockButtons) {
        blockButtons = true;
//        vector<string> langs = repo->getLangs();
//        foreach(string str, langs) {
//            qDebug() << str.c_str();
//        }

        vector<Source *> sources = repo->getSources("Chinese");
        Source *source = sources[0];

        curData = mainWindow->getData(source);
    }
}

void ListWidget::updateStatus() {
    if (curData != nullptr && curData->isTextReady()) {
        if (mainWindow->widgetNum == 0) {
            mainWindow->enablePlayer(curData);
        }
    }
}
