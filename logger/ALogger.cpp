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

bool ALogger::info(const std::string &msg, int line, const char *funcName, const char *fileName)
{
    if (!filter(LogLevel::INFO))
        return true;
    LogEntry entry{msg, LogLevel::INFO, line, funcName, fileName};
    return log(entry);
}

bool ALogger::warn(const std::string &msg, int line, const char *funcName, const char *fileName)
{
    if (!filter(LogLevel::WARN))
        return true;
    LogEntry entry{msg, LogLevel::INFO, line, funcName, fileName};
    return log(entry);
}

void ALogger::registerFilter(std::shared_ptr<IFilter> filter)
{
    _filters.push_back(filter);
}
