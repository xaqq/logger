/*
 * File:   DefaultFormatter.cpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:55 PM
 */

#include "DefaultFormatter.hpp"
#include <sstream>

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
    }
    return "UNKNOWN";
}

std::string DefaultFormatter::format(const LogEntry &entry)
{
  std::stringstream ss;
  ss << "[" << logLevelToString(entry.level) << "] @ " << entry.funcName;
  ss << ", line " << entry.line << " in ";
  ss << entry.fileName << ": " << entry.msg;

  return ss.str();
}
