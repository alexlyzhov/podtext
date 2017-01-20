#include "data.h"

Data::Data()
{
    textReady = false;
}

void Data::parseText() {
    Parser parser(text);
    text = parser.parse();
    textReady = true;
}

bool Data::isTextReady() {
    return textReady;
}
