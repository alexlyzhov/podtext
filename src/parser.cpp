#include "parser.h"

using namespace std;

Parser::Parser(QString text)
{
    this->text = text.toStdString();
}

QString Parser::parse(string sourceName) {
    if (sourceName == "Slow Chinese") {
        string startMarker("<div id=\"-0\">");
        string endMarker("</div>");
        size_t startPos = text.find(startMarker) + startMarker.length();
        size_t endPos = text.find(endMarker, startPos);
        string actualText = text.substr(startPos, endPos - startPos);
        vector<string> tags = {"<p>", "</p>"};
        bool firstPar = true;
        foreach(string tag, tags) {
            while(true) {
                size_t pos = actualText.find(tag);
                if (pos == string::npos) {
                    break;
                }
                actualText.erase(pos, tag.length());
                if ((!firstPar) && (tag == "<p>")) {
                    qDebug() << "insert";
                    actualText.insert(pos, "\n");
                }
                if (firstPar) {
                    firstPar = false;
                }
            }
        }

        qDebug() << actualText.c_str();
        text = actualText;
    } else {
        qDebug() << "Cannot parse this type of text data";
    }

    return QString::fromStdString(text);
}
