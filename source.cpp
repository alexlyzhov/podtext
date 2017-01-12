#include "source.h"

using namespace std;

Source::~Source() {

}

Source::Source(string audioUrl, string textUrl)
{
    this->audioUrl = audioUrl;
    this->textUrl = textUrl;
}

string Source::getAudioUrl() {
    return audioUrl;
}

string Source::getTextUrl() {
    return textUrl;
}
