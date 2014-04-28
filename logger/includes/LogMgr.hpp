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
/*
 * File:   LogMgr.hpp
 * Author: xaqq
 *
 * Created on August 8, 2013, 10:30 PM
 */

#ifndef LOGMGR_HPP
#define	LOGMGR_HPP

#include <memory>
#include <map>
#include <string>
#include <mutex>

namespace Log
{
  class ALogger;
  enum class LogLevel;

  class LogMgr
  {
  public:
    LogMgr() {}
    LogMgr(const LogMgr &) = delete;
    

    static void registerLogger(const std::string &name,
			       std::shared_ptr<ALogger> logger);
    static bool log(const std::string &msg, int line, const char *funcName,
		    const char *fileName, LogLevel level,
		    std::initializer_list<std::string> loggers);

  private:
    static std::map<std::string, std::shared_ptr<ALogger>> _loggers;
    static std::mutex mutex_;
  };

}

#endif	/* LOGMGR_HPP */
