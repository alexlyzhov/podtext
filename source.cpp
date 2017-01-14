#include "source.h"

using namespace std;

Source::~Source() {

}

Source::Source(string name, string audioUrl, string textUrl)
// take string info as a parameter and then parse it
{
    this->name = name;
    this->audioUrl = audioUrl;
    this->textUrl = textUrl;
}

string Source::getAudioUrl() {
    return audioUrl;
}

string Source::getTextUrl() {
    return textUrl;
}

string Source::getName() {
    return name;
}
