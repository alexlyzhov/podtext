#include "reader.h"

Reader::Reader(LocalSource *sourceParam) : DataCreator(sourceParam) {
    localSource = static_cast<LocalSource *>(source);
}

LocalData *Reader::getData() {
    // read data from file
    // addresses are specified in localSource
    // return LocalData pointer
    return nullptr;
}
