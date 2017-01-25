#include "data.h"

Data::Data() : textReady(false)
{

}

Data::~Data() {

}

void Data::parseText() {
    Parser parser(text);
    text = parser.parse(name);
    textReady = true;
}

bool Data::isTextReady() {
    return textReady;
}
