#include "textview.h"

using namespace std;

TextView::TextView(Data *data) : QLabel(data->text)
{
    this->data = data;
//    setTextFormat(Qt::RichText); // create label subclass
    setTextInteractionFlags(Qt::TextSelectableByMouse);
    setWordWrap(true);
    setFixedWidth(680);
}

string TextView::getTranslationText() {
    return selectedText().toStdString();
}

void TextView::translateText() {
    qDebug() << getTranslationText().c_str();
    if (data->language == "Chinese") {
        string urlStr = "http://ce.linedict.com/#/cnen/search?query=";
        urlStr.append(getTranslationText());
        qDebug() << "opening url" << urlStr.c_str();
        QUrl url(QString::fromStdString(urlStr));
        QDesktopServices::openUrl(url);
    }
}

void TextView::focusOutEvent(QFocusEvent *ev) {
    // override to maintain text selection

//    qDebug() << "focus out";
}
