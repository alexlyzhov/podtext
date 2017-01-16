#ifndef SOURCE_H
#define SOURCE_H

#include <string>

using namespace std;

class Source
{
    string name;
    string language;
public:
    Source(string name, string language);
    virtual ~Source();
    string getName();
    string getLanguage();
};

#endif // SOURCE_H
