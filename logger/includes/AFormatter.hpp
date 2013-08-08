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

#ifndef AFORMATTER_HPP
#define	AFORMATTER_HPP

#include <memory>
#include <string>

#include "ALogger.hpp"

namespace Log
{
class ALogger;
class LogEntry;

class AFormatter
{
public:

    AFormatter();
    AFormatter(const AFormatter &) = delete;

    virtual ~AFormatter()
    {
    }
    virtual std::string format(const LogEntry &entry) = 0;

    ALogger *logger()
    {
        return _logger;
    }

    void setLogger(ALogger *logger)
    {
        _logger = logger;
    }

private:
    ALogger *_logger;
};
}


#endif	/* AFORMATTER_HPP */

