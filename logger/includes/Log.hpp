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
 * Header file that provide the logging macros.
 * The is the main header file of the library. It provides the macro that the
 * end user should use for logging.
 *
 * *Note: sstream is included because it is required in an internal macro.*
 *
 *
 * <h2>Internal macros documentation:</h2>
 * The logging macros are available in two form:
 *   - One parameter macro: the logging message.
 *   - Two parameters macro: the logging message and a std::initializer_list of strings
 *     that are the name of the targeted logger(s).
 *
 * To do this, we use variadic macros. For example:
 *   - INFO(...) is the public macro that supports both forms of calls.
 *   - INFO_0(msg) is the internal macro that implements the behavior for 1 parameter call.
 *   - INFO_1(msg, loggers) implements the 2 parameters call.
 *   - INFO_X(trash, msg, loggers, targetMacro, ...) is the "dispatching" macro.
 *   - INFO_NO_PARAM is the macro for the 0 parameter call. It doesn't exist,
 *     the if this macro gets called, it will raise an error.
 */

#ifndef LOG_HPP
#define	LOG_HPP

#include <string>
#include "LogMgr.hpp"
#include <sstream>

/**
 * @def FUNCTION_NAME_MACRO
 * Macro used to get the name of the function that called the logging macro.
 * GNU compilers provide a nice macro the get a more detailed name of a function.
 * Otherwise we fallback to a more widespread macro.
 */

#ifdef __GNUC__
#define FUNCTION_NAME_MACRO __PRETTY_FUNCTION__
#else
#define FUNCTION_NAME_MACRO __FUNCTION__
#endif

/**
 * Internal macro.
 * It is used to create an anonymous lambda to allow the logging macros parameter
 * to behave like a stringstream.
 */
#define BUILD(param) [&] (void) {std::stringstream ss; ss << param; return ss.str();}()

/**
 * See "Internal macros documentation"
 */
#define DEBUG_0(msg) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
				      __FILE__, ::Log::LogLevel::DEBUG, {})

/**
 * See "Internal macros documentation"
 */
#define DEBUG_1(msg, loggers) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
					       __FILE__, ::Log::LogLevel::DEBUG, loggers)

/**
 * See "Internal macros documentation"
 */
#define DEBUG_X(trash, msg, loggers, targetMacro, ...) targetMacro

/**
 * Debug macro.
 * Issue a log message with DEBUG level
 */
#define DEBUG(...) DEBUG_X(, ##__VA_ARGS__,	\
			  DEBUG_1(__VA_ARGS__),	\
			  DEBUG_0(__VA_ARGS__),	\
			  DEBUG_NO_PARAM(__VA_ARGS__),	\
			  )

/**
 * See "Internal macros documentation"
 */
#define INFO_0(msg) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
				      __FILE__, ::Log::LogLevel::INFO, {})

/**
 * See "Internal macros documentation"
 */
#define INFO_1(msg, loggers) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
					       __FILE__, ::Log::LogLevel::INFO, loggers)

/**
 * See "Internal macros documentation"
 */
#define INFO_X(trash, msg, loggers, targetMacro, ...) targetMacro

/**
 * Information macro.
 * Issue a log message with INFO level.
 */
#define INFO(...) INFO_X(, ##__VA_ARGS__,	\
			  INFO_1(__VA_ARGS__),	\
			  INFO_0(__VA_ARGS__),	\
			  INFO_NO_PARAM(__VA_ARGS__),	\
			  )

/**
 * See "Internal macros documentation"
 */
#define WARN_0(msg) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
				      __FILE__, ::Log::LogLevel::WARN, {})

/**
 * See "Internal macros documentation"
 */
#define WARN_1(msg, loggers) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
					       __FILE__, ::Log::LogLevel::WARN, loggers)

/**
 * See "Internal macros documentation"
 */
#define WARN_X(trash, msg, loggers, targetMacro, ...) targetMacro

/**
 * Warning macro.
 * Issue a log message with WARN level.
 */
#define WARN(...) WARN_X(, ##__VA_ARGS__,	\
			  WARN_1(__VA_ARGS__),	\
			  WARN_0(__VA_ARGS__),	\
			  WARN_NO_PARAM(__VA_ARGS__),	\
			  )

/**
 * See "Internal macros documentation"
 */
#define ERROR_0(msg) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
				      __FILE__, ::Log::LogLevel::ERROR, {})
/**
 * See "Internal macros documentation"
 */
#define ERROR_1(msg, loggers) Log::LogMgr::log(BUILD(msg), __LINE__, FUNCTION_NAME_MACRO, \
					       __FILE__, ::Log::LogLevel::ERROR, loggers)
/**
 * See "Internal macros documentation"
 */
#define ERROR_X(trash, msg, loggers, targetMacro, ...) targetMacro

/**
 * Error macro.
 * Issue a log message with ERROR level
 */
#define ERROR(...) ERROR_X(, ##__VA_ARGS__,	\
			  ERROR_1(__VA_ARGS__),	\
			  ERROR_0(__VA_ARGS__),	\
			  ERROR_NO_PARAM(__VA_ARGS__),	\
			  )

namespace Log
{
/**
 * @addtogroup Log
 * @{
 */

/**
 * The LogLevel enum.
 * It enumerates the different loglevels.
 */
enum class LogLevel
{
    DEBUG,
    INFO,
    WARN,
    ERROR,
};

/*! @} */

}

#endif	/* LOG_HPP */
