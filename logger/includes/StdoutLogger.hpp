/*
 * File:   StdoutLogger.hpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:44 PM
 */

#ifndef STDOUTLOGGER_HPP
#define	STDOUTLOGGER_HPP

#include "ALogger.hpp"
namespace Log
{

class StdoutLogger : public ALogger
{
public:
    StdoutLogger();
    StdoutLogger(const StdoutLogger& orig) = delete;
    virtual ~StdoutLogger();

private:
    virtual bool log(const LogEntry &entry);
};
}

#endif	/* STDOUTLOGGER_HPP */

