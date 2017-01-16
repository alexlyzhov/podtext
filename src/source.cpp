#include "source.h"

using namespace std;

Source::Source(string name, string language)
{
    this->name = name;
    this->language = language;
}

Source::~Source() {

}

string Source::getName() {
    return name;
}

string Source::getLanguage() {
    return name;
}
