#include "source.h"

using namespace std;

Source::Source(string name)
{
    this->name = name;
}

Source::~Source() {

}

string Source::getName() {
    return name;
}
