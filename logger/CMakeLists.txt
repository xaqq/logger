cmake_minimum_required (VERSION 2.6)
project (Logger)

# Compiler flags
set (CMAKE_CXX_FLAGS "-std=c++11 -W -Wall -g")

set (SOURCES 
  "ALogger.cpp"
  "DefaultFilter.cpp"
  "DefaultFormatter.cpp"
  "LogMgr.cpp"
  "StdoutLogger.cpp"
)

add_library(Logger ${SOURCES})
