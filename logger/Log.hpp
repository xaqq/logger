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
# define INFO(msg) Log::LogMgr::info(msg, __LINE__, __FUNCTION__, __FILE__)
#else
# define INFO(msg) Log::LogMgr::info(msg, __LINE__, __FUNCTION__, __FILE__)
#endif

namespace Log
{

enum LogLevel
{
    INFO,
    WARN,
};
}

#endif	/* LOG_HPP */

