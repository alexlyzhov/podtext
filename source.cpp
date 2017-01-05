#include "source.h"

using namespace std;

Source::Source(string url)
{
    this->url = url;
}

string Source::getUrl() {
    return url;
}
