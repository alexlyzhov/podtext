#include "remotesource.h"

RemoteSource::RemoteSource(string name, string audioUrl, string textUrl) : Source(name)
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
