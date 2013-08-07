/*
 * File:   LogEntry.hpp
 * Author: xaqq
 *
 * Created on August 8, 2013, 12:05 AM
 */

#ifndef LOGENTRY_HPP
#define	LOGENTRY_HPP

#include "Log.hpp"


namespace Log
{

struct LogEntry
{
    std::string msg;
    LogLevel    level;
};
}
#endif	/* LOGENTRY_HPP */

