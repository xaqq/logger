/*
 * File:   AFormatter.hpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:50 PM
 */

#ifndef AFORMATTER_HPP
#define	AFORMATTER_HPP

#include "ALogger.hpp"
#include "LogEntry.hpp"


namespace Log
{

class AFormatter
{
public:

    AFormatter(std::weak_ptr<ALogger> logger) : _logger(logger)
    {
    }
    AFormatter(const AFormatter &) = delete;

    virtual std::string format(const LogEntry &entry) = 0;

    std::shared_ptr<ALogger> logger()
    {
        return _logger.lock();
    }

private:
    std::weak_ptr<ALogger> _logger;
};
}


#endif	/* AFORMATTER_HPP */

