/*
 *  CPPLogger, a C++ library that provide an easy and way to do logging.
 *  Copyright (C) 2013  Kapp Arnaud
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see [http://www.gnu.org/licenses/].
 */

#include <stdexcept>
#include "LogMgr.hpp"
#include "ALogger.hpp"
#include "LogEntry.hpp"

using namespace Log;

std::map<std::string, std::shared_ptr<ALogger >> LogMgr::_loggers;
std::atomic_bool LogMgr::isLogging_;

void LogMgr::registerLogger(const std::string &name, std::shared_ptr<ALogger> logger)
{
    _loggers[name] = logger;
}

bool LogMgr::log(const std::string &msg, int line, const char *funcName,
                 const char *fileName, LogLevel level,
                 std::initializer_list<std::string> loggers)
{
    bool retval;
    LogEntry entry{msg, level, line, funcName, fileName};

    while (isLogging_);
    isLogging_ = true;
    retval = true;
    
    if (loggers.size())
    {
        for (auto loggerName : loggers)
        {
            if (_loggers.find(loggerName) == _loggers.end())
                throw std::runtime_error("Logger not found!");
            if (!_loggers[loggerName]->filter(entry))
                continue;
            retval &= _loggers[loggerName]->log(entry);
        }
    }
    else
    {
        for (std::pair<const std::string, std::shared_ptr < ALogger >> &logger : _loggers)
        {
            if (!logger.second->filter(entry))
                continue;
            retval &= logger.second->log(entry);
        }
    }
    isLogging_ = false;
    return retval;
}
