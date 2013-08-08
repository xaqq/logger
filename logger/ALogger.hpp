/*
 * File:   ALogger.hpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:18 PM
 */

#ifndef ALOGGER_HPP
#define	ALOGGER_HPP

#include <memory>
#include <string>
#include <list>
#include "Log.hpp"
#include "LogEntry.hpp"


namespace Log
{

class IFilter;
class AFormatter;
class LogMgr;

class ALogger
{
public:
    ALogger();
    ALogger(const ALogger &) = delete;
    virtual ~ALogger();

    bool filter(LogEntry entry);
    void registerFilter(std::shared_ptr<IFilter> filter);

    void setFormatter(std::shared_ptr<AFormatter> formatter)
    {
        _formatter = formatter;
    }

    std::shared_ptr<AFormatter> formatter()
    {
        return _formatter;
    }


  friend class LogMgr;
protected:
    std::shared_ptr<AFormatter> _formatter;

private:
    virtual bool log(const LogEntry &entry) = 0;
    std::list<std::shared_ptr<IFilter >> _filters;
};
}
#endif	/* ALOGGER_HPP */

