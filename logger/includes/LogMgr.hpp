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
  };

}

#endif	/* LOGMGR_HPP */
