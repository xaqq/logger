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

#ifndef SIMPLEFORMATTER_HPP
#define	SIMPLEFORMATTER_HPP

#include "AFormatter.hpp"

namespace Log
{
  enum class LogLevel;

  class SimpleFormatter : public AFormatter
  {
  public:

    SimpleFormatter() { }

    SimpleFormatter(const SimpleFormatter& orig) = delete;
    virtual ~SimpleFormatter();

    virtual std::string format(const LogEntry &entry);
  };
}
#endif	/* SIMPLEFORMATTER_HPP */

