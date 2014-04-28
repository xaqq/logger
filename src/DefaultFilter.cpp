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
 * File:   DefaultFilter.cpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:39 PM
 */

#include "DefaultFilter.hpp"
#include "LogEntry.hpp"
#include <algorithm>

using namespace Log;

DefaultFilter::DefaultFilter(LogLevel minLevel) :
  _useMinLevel(true),
  _minLevel(minLevel)
{
}

DefaultFilter::DefaultFilter(std::initializer_list<LogLevel> l) :
  _useMinLevel(false),
  _levels(l)
{
}

DefaultFilter::~DefaultFilter()
{
}

bool DefaultFilter::filter(const LogEntry &entry)
{
  if (_useMinLevel)
    return entry.level >= _minLevel;
  return std::find(_levels.begin(), _levels.end(), entry.level) != _levels.end();
}
