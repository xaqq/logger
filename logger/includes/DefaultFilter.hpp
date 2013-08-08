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

