cmake_minimum_required(VERSION 3.14)

project("example")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD            23)
set(CMAKE_CXX_STANDARD_REQUIRED  YES)
set(CMAKE_CXX_EXTENSIONS         OFF)
set(CMAKE_CXX_FLAGS_RELEASE    "-O3")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(.. ${CMAKE_BINARY_DIR}/logger)

add_executable(exec
  example.cpp
)

target_link_libraries(exec PRIVATE logger)

