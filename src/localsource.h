#ifndef LOCALSOURCE_H
#define LOCALSOURCE_H

#include <string>
#include "source.h"

class LocalSource : public Source
{
public:
    LocalSource(string name, string audioAddress, string textAddress);
};

#endif // LOCALSOURCE_H
