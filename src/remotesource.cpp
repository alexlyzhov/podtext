#include "remotesource.h"

RemoteSource::RemoteSource(string name, string lang, string audioUrl, string textUrl) : Source(name, lang)
{
    this->audioUrl = audioUrl;
    this->textUrl = textUrl;
}

string RemoteSource::getAudioUrl() {
    return audioUrl;
}

string RemoteSource::getTextUrl() {
    return textUrl;
}
