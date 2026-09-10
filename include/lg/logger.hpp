#ifndef LOGGER_HPP_
#define LOGGER_HPP_
#include <mutex>
#include <string>

namespace lg {
/**
 *  @brief Log manages logging with levels and timestamps.
 *
 *  Log should not be created by the user, the library exposes it as in inline
 * variable log. It is responsible for filtering logs based on their level and
 * creating threads that safely put logs on the screen.
 */
inline class Log {
public:
  /**
   * @brief Enum specifying the log level
   */
  enum class LogLevel {
    info = 0x01,
    warning = 0x02,
    error = 0x04,
    debug = 0x08,
    memory = 0x10
  };

private:
  short _level = (short)LogLevel::info | (short)LogLevel::warning |
                 (short)LogLevel::error | (short)LogLevel::debug |
                 (short)LogLevel::memory;
  static std::mutex _mutex;

public:
  /**
   * @brief Prints out a log with a set log level
   *
   * Firstly checks if the log level is supposed to be printed, then
   * to avoid freezing the main thread creates a new one to print
   * the log message.
   *
   * @param level log level to print on
   * @param text log message
   */
  void operator()(LogLevel level, std::string text);

  /**
   * @brief Prints out a log with a default log level of info.
   *
   * Firstly checks if the log level is supposed to be printed, then
   * to avoid freezing the main thread creates a new one to print
   * the log message.
   *
   * @param text log message
   */
  void operator()(std::string text);

  /**
   * @brief Sets the levels that are supposed to be displayed.
   *
   * By default thats all levels, set the levels from enum class
   * lg::Log::LogLevel, casting them to short and or'ing them with |
   *
   * @param log_level log levels to show
   */
  void SetLevel(short log_level);

private:
  static void Log_(std::string text, enum LogLevel level);

  static std::string LogLevelToText_(enum LogLevel);
} log;
} // namespace lg

#endif
