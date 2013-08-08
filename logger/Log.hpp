/*
 * File:   Log.hpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:30 PM
 */

#ifndef LOG_HPP
#define	LOG_HPP

#include <string>
#include "LogMgr.hpp"

#ifdef __GNUC__
# define INFO(msg) Log::LogMgr::log(msg, __LINE__, __PRETTY_FUNCTION__,\
				    __FILE__, ::Log::LogLevel::INFO)

# define WARN(msg) Log::LogMgr::log(msg, __LINE__, __PRETTY_FUNCTION__,\
				    __FILE__, ::Log::LogLevel::WARN)

# define ERROR(msg) Log::LogMgr::log(msg, __LINE__, __PRETTY_FUNCTION__,\
				    __FILE__, ::Log::LogLevel::ERROR)
#else
# define INFO(msg) Log::LogMgr::log(msg, __LINE__, __FUNCTION__, __FILE__, ::Log::LogLevel::INFO)
# define WARN(msg) Log::LogMgr::log(msg, __LINE__, __FUNCTION__, __FILE__, ::Log::LogLevel::WARN)
# define ERROR(msg) Log::LogMgr::log(msg, __LINE__, __FUNCTION__, __FILE__, ::Log::LogLevel::ERROR)
#endif

namespace Log
{

  enum class LogLevel
  {
    DEBUG,
      INFO,
      WARN,
      ERROR,
      };
}

#endif	/* LOG_HPP */

