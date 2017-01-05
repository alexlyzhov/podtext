#ifndef SOURCE_H
#define SOURCE_H

#include <string>

using namespace std;

class Source
{
    string url;
public:
    Source(string url);
    string getUrl();
};

#endif // SOURCE_H
