#ifndef READER_H
#define READER_H

#include "datacreator.h"
#include "localdata.h"
#include "localsource.h"

class Reader : public DataCreator
{
    LocalSource *localSource;
public:
    Reader(LocalSource *localSource);
    LocalData *getData();
};

#endif // READER_H
