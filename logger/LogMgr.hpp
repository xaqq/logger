/*
 * File:   LogMgr.hpp
 * Author: xaqq
 *
 * Created on August 8, 2013, 10:30 PM
 */

#ifndef LOGMGR_HPP
#define	LOGMGR_HPP

#include <memory>
#include <list>

namespace Log
{
  class ALogger;
  class LogMgr
  {
  public:
    LogMgr() {}
    LogMgr(const LogMgr &) = delete;
    

    static void registerLogger(std::shared_ptr<ALogger> logger);
    static bool info(const std::string &msg, int line, const char *funcName, const char *fileName);

  private:
    static std::list<std::shared_ptr<ALogger>> _loggers;
  };

}

#endif	/* LOGMGR_HPP */

#
