#ifndef SOURCE_H
#define SOURCE_H

#include <string>

using namespace std;

class Source
{
    string name;
    string audioUrl;
    string textUrl;
public:
    Source(string name, string audioUrl, string textUrl);
    virtual ~Source();
    string getName();
    string getAudioUrl();
    string getTextUrl();
};

#endif // SOURCE_H
