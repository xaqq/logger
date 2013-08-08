/*
 * File:   LogMgr.cpp
 * Author: xaqq
 *
 * Created on August 8, 2013, 10:30 PM
 */

#include "LogMgr.hpp"
#include "ALogger.hpp"

using namespace Log;

std::list<std::shared_ptr<ALogger>> LogMgr::_loggers;

void LogMgr::registerLogger(std::shared_ptr<ALogger> logger)
{
  _loggers.push_back(logger);
}

bool LogMgr::info(const std::string &msg, int line, const char *funcName, const char *fileName)
{
  bool retval;
  LogEntry entry {msg, LogLevel::INFO, line, funcName, fileName};

  retval = true;
  for (std::shared_ptr<ALogger> logger : _loggers)
    {
      if (!logger->filter(entry))
	continue;
      retval &= logger->log(entry);
    }
  return retval;
}
