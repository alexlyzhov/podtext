#include "datacreator.h"

DataCreator::DataCreator(Source *source_param) {
    source = source_param;

    this->name = source->getName();
    this->language = source->getLanguage();
}

DataCreator::~DataCreator()
{
	delete(source);
}
