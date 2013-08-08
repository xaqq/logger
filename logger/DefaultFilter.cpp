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
