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
 * File:   DefaultFilter.hpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:39 PM
 */

#ifndef DEFAULTFILTER_HPP
#define	DEFAULTFILTER_HPP

#include "IFilter.hpp"
#include <vector>

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
  DefaultFilter(LogLevel minLevel = LogLevel::DEBUG);
  DefaultFilter(std::initializer_list<LogLevel> l);
    DefaultFilter(const DefaultFilter& orig) = delete;
    virtual ~DefaultFilter();

    virtual bool filter(const LogEntry& entry);

private:

  /**
   * Set to false if the filter was initialized using the initializer_list ctor
   */
  bool _useMinLevel;

  LogLevel _minLevel;
  std::vector<LogLevel> _levels;
};
}
#endif	/* DEFAULTFILTER_HPP */

