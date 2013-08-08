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
