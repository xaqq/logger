/*
 * File:   DefaultFormatter.cpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:55 PM
 */

#include "DefaultFormatter.hpp"

using namespace Log;

DefaultFormatter::~DefaultFormatter()
{
}

std::string DefaultFormatter::logLevelToString(LogLevel level) const
{
    switch (level)
    {
    case LogLevel::INFO:
        return "INFO";
    case LogLevel::WARN:
        return "WARNING";
    default:
        return "UNKNOWN";
    }
}

std::string DefaultFormatter::format(const LogEntry &entry)
{
    return std::string("[" + logLevelToString(entry.level) + "]: " + entry.msg);
}