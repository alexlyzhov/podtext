#ifndef SOURCE_H
#define SOURCE_H

#include <string>

using namespace std;

class Source
{
    string name;
public:
    Source(string name);
    virtual ~Source();
    string getName();
};

#endif // SOURCE_H
