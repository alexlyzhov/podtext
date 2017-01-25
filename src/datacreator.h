#ifndef DATACREATOR_H
#define DATACREATOR_H

#include "source.h"
#include "data.h"

class DataCreator
{
    // Factory method
    // AbstractCreator: DataCreator
    // ConcreteCreater: Downloader, Reader
    // AbstractProduct: Data
    // ConcreteProduct: RemoteData, LocalData
protected:
    Source *source;
    string name;
    string language;
public:
    DataCreator(Source *source);
    virtual Data *getData() = 0;
    ~DataCreator();
};

#endif // DATACREATOR_H
