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
 * File:   StdoutLogger.cpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:44 PM
 */

#include "StdoutLogger.hpp"
#include "AFormatter.hpp"
#include <iostream>

using namespace Log;

StdoutLogger::StdoutLogger()
{
}

StdoutLogger::~StdoutLogger()
{
}

bool StdoutLogger::log(const LogEntry &entry)
{
  std::cout << _formatter->format(entry) << std::endl;
  return true;
}
