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

/**
 * @file
 * @brief test brief
 * @author xaqq
 *
 * Blabla more
 */

#ifndef LOG_HPP
#define	LOG_HPP

#include <string>
#include "LogMgr.hpp"

#ifdef __GNUC__
#define FUNCTION_NAME_MACRO __PRETTY_FUNCTION__
#else
#define FUNCTION_NAME_MACRO __FUNCTION__
#endif

/** Pretty cool macro */
#define BUILD(param) [&] (void) { std::stringstream ss; ss << param; return ss.str();}()

/* Let the log entry be dispatched to all loggers */
#define DEBUG_0(msg) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
				      __FILE__, ::Log::LogLevel::DEBUG, {})

/* Macro to specify target logger(s) */
#define DEBUG_1(msg, loggers) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
					       __FILE__, ::Log::LogLevel::DEBUG, loggers)

/* Is here to strip useless extra parameter and call the approriate macro */
#define DEBUG_X(trash, msg, loggers, targetMacro, ...) targetMacro

/* DEBUG_NO_PARAM is a undefined macro, but it is required here for DEBUG_X to work */
#define DEBUG(...) DEBUG_X(, ##__VA_ARGS__,	\
			  DEBUG_1(__VA_ARGS__),	\
			  DEBUG_0(__VA_ARGS__),	\
			  DEBUG_NO_PARAM(__VA_ARGS__),	\
			  )

/* Let the log entry be dispatched to all loggers */
#define INFO_0(msg) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
				      __FILE__, ::Log::LogLevel::INFO, {})

/* Macro to specify target logger(s) */
#define INFO_1(msg, loggers) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
					       __FILE__, ::Log::LogLevel::INFO, loggers)

/* Is here to strip useless extra parameter and call the approriate macro */
#define INFO_X(trash, msg, loggers, targetMacro, ...) targetMacro

/* INFO_NO_PARAM is a undefined macro, but it is required here for INFO_X to work */
#define INFO(...) INFO_X(, ##__VA_ARGS__,	\
			  INFO_1(__VA_ARGS__),	\
			  INFO_0(__VA_ARGS__),	\
			  INFO_NO_PARAM(__VA_ARGS__),	\
			  )

/* Let the log entry be dispatched to all loggers */
#define WARN_0(msg) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
				      __FILE__, ::Log::LogLevel::WARN, {})

/* Macro to specify target logger(s) */
#define WARN_1(msg, loggers) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
					       __FILE__, ::Log::LogLevel::WARN, loggers)

/* Is here to strip useless extra parameter and call the approriate macro */
#define WARN_X(trash, msg, loggers, targetMacro, ...) targetMacro

/* WARN_NO_PARAM is a undefined macro, but it is required here for WARN_X to work */
#define WARN(...) WARN_X(, ##__VA_ARGS__,	\
			  WARN_1(__VA_ARGS__),	\
			  WARN_0(__VA_ARGS__),	\
			  WARN_NO_PARAM(__VA_ARGS__),	\
			  )

/* Let the log entry be dispatched to all loggers */
#define ERROR_0(msg) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
				      __FILE__, ::Log::LogLevel::ERROR, {})

/* Macro to specify target logger(s) */
#define ERROR_1(msg, loggers) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
					       __FILE__, ::Log::LogLevel::ERROR, loggers)

/* Is here to strip useless extra parameter and call the approriate macro */
#define ERROR_X(trash, msg, loggers, targetMacro, ...) targetMacro

/* ERROR_NO_PARAM is a undefined macro, but it is required here for ERROR_X to work */
#define ERROR(...) ERROR_X(, ##__VA_ARGS__,	\
			  ERROR_1(__VA_ARGS__),	\
			  ERROR_0(__VA_ARGS__),	\
			  ERROR_NO_PARAM(__VA_ARGS__),	\
			  )



namespace Log
{

enum class LogLevel
{
    DEBUG,
    INFO,
    WARN,
    ERROR,
};

}

#endif	/* LOG_HPP */

