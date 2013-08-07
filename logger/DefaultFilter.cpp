/*
 * File:   DefaultFilter.cpp
 * Author: xaqq
 *
 * Created on August 7, 2013, 11:39 PM
 */

#include "DefaultFilter.hpp"
using namespace Log;

DefaultFilter::DefaultFilter(LogLevel minLevel) : _minLevel(minLevel)
{
}

DefaultFilter::~DefaultFilter()
{
}

bool DefaultFilter::filter(LogLevel level)
{
    return level >= _minLevel;
}