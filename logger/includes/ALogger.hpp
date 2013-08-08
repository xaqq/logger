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

#ifndef ALOGGER_HPP
#define	ALOGGER_HPP

#include <memory>
#include <string>
#include <list>

#include "AFormatter.hpp"

namespace Log
{

class IFilter;
class AFormatter;
class LogMgr;
class LogEntry;

class ALogger
{
public:
    ALogger(AFormatter *formatter);
    ALogger(const ALogger &) = delete;
    virtual ~ALogger();

    bool filter(const LogEntry &entry);
    void registerFilter(std::shared_ptr<IFilter> filter);

    void setFormatter(AFormatter *formatter)
    {
        _formatter = formatter;
    }

    AFormatter *formatter()
    {
        return _formatter;
    }


    friend class LogMgr;
protected:
    AFormatter *_formatter;

private:
    virtual bool log(const LogEntry &entry) = 0;
    std::list<std::shared_ptr<IFilter >> _filters;
};
}
#endif	/* ALOGGER_HPP */

