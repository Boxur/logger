cmake_minimum_required(VERSION 3.14)

project("logger")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD            17)
set(CMAKE_CXX_STANDARD_REQUIRED  YES)
set(CMAKE_CXX_EXTENSIONS         OFF)
set(CMAKE_CXX_FLAGS_RELEASE    "-O3")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_library(logger STATIC
  src/logger.cpp
)

target_include_directories(logger PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
