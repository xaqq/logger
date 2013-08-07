/*
 * File:   IFilter.hpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:29 PM
 */

#ifndef IFILTER_HPP
#define	IFILTER_HPP

#include "Log.hpp"

namespace Log
{

class IFilter
{
public:

    IFilter()
    {
    }

    virtual ~IFilter()
    {
    }
    IFilter(const IFilter &) = delete;

    virtual bool filter(LogLevel level) = 0;
};
}


#endif	/* IFILTER_HPP */

