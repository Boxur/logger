# Logger

A simple logging library utilising multithreading to avoid stopping the main
thread's work.

[![Build](https://github.com/Boxur/logger/actions/workflows/documentation.yml/badge.svg)](https://github.com/boxur/logger/actions)
[![Documentation](https://img.shields.io/badge/docs-online-blue)](https://logger.documentation.boxur.org/)
[![License](https://img.shields.io/github/license/boxur/logger)](https://github.com/Boxur/logger/blob/main/LICENSE)
[![Top Language](https://img.shields.io/github/languages/top/boxur/logger)](https://github.com/boxur/logger)

## Features

 - Setting the log levels.
 - Logging messages to the console.
 - Creating seperate threads to let the main thread run without stopping.

## Requirements

 - C++23 compiler
 - CMake 3.14+
 - Git

## Instalation

Clone from github:
```bash
git clone https://github.com/Boxur/logger external/logger
```

### CMake
Add to your project in CMake:
```cmake
add_subdirectory(external/logger)

target_link_libraries(project PRIVATE logger)
```

## Examples

Each of the examples assumes the following header is included
```cpp
#include <lg/logger.hpp>
```

Setting the log level to only display error messages
```cpp
lg::log.SetLevel((short)lg::Log::LogLevel::error);
```

Printing a log of default level info
```cpp
lg::log("Message");
```

Printing a log of level error
```cpp
lg::log(lg::Log::LogLevel::error, "Error log");
```

An example of all three code fragments can be found at
[Example](https://github.com/Boxur/logger/blob/main/examples/example.cpp)

## Contributing

Contributions, bug reports, and suggestions are welcome.

Before submitting a pull request, please ensure that the project builds
successfully

## License

This project is licensed under the MIT License.
See [LICENSE](https://github.com/Boxur/logger/blob/main/LICENSE) for details.
