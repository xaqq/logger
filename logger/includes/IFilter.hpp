/*
 *  CPPLogger, a C++ library that provide an easy and way to do logging.
 *  Copyright (C) 2013  Kapp Arnaud
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see [http://www.gnu.org/licenses/].
 */
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
struct LogEntry;

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

    virtual bool filter(const LogEntry &entry) = 0;
};
}


#endif	/* IFILTER_HPP */

