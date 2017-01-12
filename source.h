#ifndef SOURCE_H
#define SOURCE_H

#include <string>

using namespace std;

class Source
{
    string audioUrl;
    string textUrl;
public:
    Source(string audioUrl, string textUrl);
    virtual ~Source();
    string getAudioUrl();
    string getTextUrl();
};

#endif // SOURCE_H
