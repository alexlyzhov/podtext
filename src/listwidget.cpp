#include "listwidget.h"
#include "mainwindow.h"

ListWidget::ListWidget(MainWindow *parent, Repo *repo, Settings *settings)
{
    this->mainWindow = parent;
    this->repo = repo;
    this->settings = settings; // write an interface to show and change settings in list widget

    QVBoxLayout *layout = new QVBoxLayout;

    QHBoxLayout *hlayout = new QHBoxLayout();
    QLabel *repoLabel = new QLabel(QString("Repository location: "));
    hlayout->addWidget(repoLabel);
    QLineEdit *repoEdit = new QLineEdit();
    repoEdit->setText(QString("repository.json"));
    hlayout->addWidget(repoEdit);
    QPushButton *repoButton = new QPushButton(QString("&Load"));
    hlayout->addWidget(repoButton);
    layout->addLayout(hlayout);

    QColumnView *view = new QColumnView();
    QStandardItemModel *model = new QStandardItemModel();
    vector<string> langs = repo->getLangs();
    foreach (string lang, langs) {
        QStandardItem *group = new QStandardItem(QString::fromStdString(lang));
        vector<Source *> sources = repo->getSources(lang);
        foreach (Source *source, sources) {
            QStandardItem *child = new QStandardItem(QString::fromStdString(source->getName()));
            group->appendRow(child);
        }
        model->appendRow(group); // what about appending columns?
    }
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setModel(model);
    model->setColumnCount(2);
    layout->addWidget(view);

    QPushButton *button = new QPushButton("&Play");
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    layout->addWidget(button);\

    setLayout(layout);
}

void ListWidget::buttonClicked() {
    if (!blockButtons) {
        blockButtons = true;

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
