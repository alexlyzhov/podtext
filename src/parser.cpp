#include "parser.h"

using namespace std;

Parser::Parser(QString text)
{
    this->text = text.toStdString();
}

QString Parser::parse() {
    // only applicable to the Slow Chinese podcast so far

    string startMarker("<div id=\"-0\">");
    string endMarker("</div>");
    size_t startPos = text.find(startMarker) + startMarker.length();
    size_t endPos = text.find(endMarker, startPos);
    string actualText = text.substr(startPos, endPos - startPos);
    vector<string> tags = {"<p>", "</p>"};
    foreach(string tag, tags) {
        while(true) {
            size_t pos = actualText.find(tag);
            if (pos == string::npos) {
                break;
            }
            actualText.erase(pos, tag.length());
        }
    }

    text = actualText;
    qDebug() << text.c_str();
    return QString::fromStdString(text);
}
