/*
 * File:   DefaultFormatter.hpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:55 PM
 */

#ifndef DEFAULTFORMATTER_HPP
#define	DEFAULTFORMATTER_HPP

#include "AFormatter.hpp"


namespace Log
{

class DefaultFormatter : public AFormatter
{
public:

    DefaultFormatter(std::weak_ptr<ALogger> logger) : AFormatter(logger)
    {
    }

    DefaultFormatter(const DefaultFormatter& orig) = delete;
    virtual ~DefaultFormatter();

    virtual std::string format(const LogEntry &entry);
protected:
    std::string logLevelToString(LogLevel) const;
};
}
#endif	/* DEFAULTFORMATTER_HPP */

