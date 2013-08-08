/*
 * File:   LogMgr.cpp
 * Author: xaqq
 *
 * Created on August 8, 2013, 10:30 PM
 */

#include "LogMgr.hpp"
#include "ALogger.hpp"

using namespace Log;

std::map<std::string, std::shared_ptr<ALogger>> LogMgr::_loggers;

void LogMgr::registerLogger(const std::string &name, std::shared_ptr<ALogger> logger)
{
  _loggers[name] = logger;
}

bool LogMgr::log(const std::string &msg, int line, const char *funcName,
		 const char *fileName, LogLevel level,
		 std::initializer_list<std::string> loggers)
{
  bool retval;
  LogEntry entry {msg, level, line, funcName, fileName};

  retval = true;
  
  if (loggers.size())
    {
      for (auto loggerName : loggers)
	{
	  if (!_loggers[loggerName]->filter(entry))
	    continue;
	  retval &= _loggers[loggerName]->log(entry);
	}
    }
  else
    {
      for (std::pair<const std::string, std::shared_ptr<ALogger>> &logger : _loggers)
	{
	  if (!logger.second->filter(entry))
	    continue;
	  retval &= logger.second->log(entry);
	}
    }
  return retval;
}
