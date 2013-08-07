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

bool ALogger::filter(LogLevel level)
{
    for (std::shared_ptr<IFilter> filter : _filters)
    {
        if (!filter->filter(level))
            return false;
    }
    return true;
}

bool ALogger::info(const std::string &msg)
{
    if (!filter(LogLevel::INFO))
        return false;
    LogEntry entry{msg, LogLevel::INFO};
    log(entry);
}

bool ALogger::warn(const std::string &msg)
{
    if (!filter(LogLevel::WARN))
        return false;
    LogEntry entry{msg, LogLevel::WARN};
    log(entry);
}

void ALogger::registerFilter(std::shared_ptr<IFilter> filter)
{
    _filters.push_back(filter);
}