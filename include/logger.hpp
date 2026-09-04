#ifndef LOGGER_HPP_
#define LOGGER_HPP_
#include <mutex>
#include <string>

namespace logger {
class Logger {
public:
  enum class LogLevel {
    info = 0x01,
    warning = 0x02,
    error = 0x04,
    debug = 0x08,
    memory = 0x10
  };

private:
  inline static short _level =
      (short)LogLevel::info | (short)LogLevel::warning |
      (short)LogLevel::error | (short)LogLevel::debug | (short)LogLevel::memory;
  inline static std::mutex _mutex;

public:
  static void Log(LogLevel level, std::string text);

  static void Log(std::string text);

  static void SetLogLevel(short log_level);

private:
  static void Log_(std::string text, enum LogLevel level);

  static std::string LogLevelToText(enum LogLevel);
};
} // namespace logger

#endif
