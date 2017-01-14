#ifndef REPO_H
#define REPO_H

#include <string>
#include <vector>
#include "source.h"

using namespace std;

class Repo
{
private:
    vector<string> langs;
public:
    Repo();
    virtual ~Repo();
    vector<string> getLangs();
    vector<Source> getSources(string lang);
};

#endif // REPO_H
