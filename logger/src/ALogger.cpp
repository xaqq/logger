/*
 * File:   ILogger.cpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:18 PM
 */

#include "ALogger.hpp"
#include "IFilter.hpp"
using namespace Log;

ALogger::ALogger()
{
}

ALogger::~ALogger()
{
}

bool ALogger::filter(LogEntry entry)
{
    for (std::shared_ptr<IFilter> filter : _filters)
    {
        if (!filter->filter(entry))
            return false;
    }
    return true;
}

void ALogger::registerFilter(std::shared_ptr<IFilter> filter)
{
    _filters.push_back(filter);
}
