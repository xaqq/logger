cmake_minimum_required (VERSION 2.6)
project (Logger)

# Compiler flags
set (CMAKE_CXX_FLAGS "-std=c++11 -W -Wall -g")

include_directories ("${PROJECT_SOURCE_DIR}/includes")

set (SOURCES
  "src/ALogger.cpp"
  "src/DefaultFilter.cpp"
  "src/DefaultFormatter.cpp"
  "src/LogMgr.cpp"
  "src/StdoutLogger.cpp"
)

add_library(Logger ${SOURCES})
