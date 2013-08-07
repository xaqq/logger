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

class ALogger
{
public:
    ALogger();
    ALogger(const ALogger &) = delete;
    virtual ~ALogger();

    bool filter(LogLevel level);
    void registerFilter(std::shared_ptr<IFilter> filter);

    bool info(const std::string &msg);
    bool warn(const std::string &msg);

    void setFormatter(std::shared_ptr<AFormatter> formatter)
    {
        _formatter = formatter;
    }

    std::shared_ptr<AFormatter> formatter()
    {
        return _formatter;
    }

protected:
    std::shared_ptr<AFormatter> _formatter;

private:
    virtual bool log(const LogEntry &entry) = 0;

    std::list<std::shared_ptr<IFilter >> _filters;
};
}
#endif	/* ALOGGER_HPP */

