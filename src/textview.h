#ifndef TEXTVIEW_H
#define TEXTVIEW_H

#include <QLabel>
#include <QString>
#include <string>
#include <QDebug>
#include <QFocusEvent>
#include <QDesktopServices>
#include "data.h"

using namespace std;

class TextView : public QLabel
{
    Q_OBJECT

    Data *data = nullptr;
public:
    TextView(Data *data);
    string getTranslationText();
    void focusOutEvent(QFocusEvent *ev);
    ~TextView();

public slots:
    void translateText();
};

#endif // TEXTVIEW_H
