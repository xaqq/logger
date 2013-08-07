/*
 * File:   DefaultFilter.hpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:39 PM
 */

#ifndef DEFAULTFILTER_HPP
#define	DEFAULTFILTER_HPP

#include "IFilter.hpp"

namespace Log
{

/**
 * Default filter, which accepts message whose level is greater or equal to the
 * minLevel parameter
 * @param minLevel
 */
class DefaultFilter : public IFilter
{
public:
    DefaultFilter(LogLevel minLevel);
    DefaultFilter(const DefaultFilter& orig) = delete;
    virtual ~DefaultFilter();

    virtual bool filter(LogLevel level) = 0;

    void setLevel(LogLevel level)
    {
        _minLevel = level;
    }

    LogLevel level() const
    {
        return _minLevel;
    }

private:
    LogLevel _minLevel;
};
}
#endif	/* DEFAULTFILTER_HPP */

