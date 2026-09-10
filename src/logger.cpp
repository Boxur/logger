#include <lg/logger.hpp>
#include <mutex>
#include <thread>

namespace lg {
std::mutex Log::_mutex;
void Log::operator()(enum LogLevel level, std::string text) {
  if ((_level & (short)level) != (short)level || text == "")
    return;
  std::thread thread(&Log::Log_, text, level);
  thread.detach();
}

void Log::operator()(std::string text) {
  Log::operator()(Log::LogLevel::info, text);
}

void Log::SetLevel(short log_level) { _level = log_level; }

void Log::Log_(std::string text, enum LogLevel level) {

  std::chrono::system_clock::time_point td = std::chrono::system_clock::now();
  auto td_days = std::chrono::time_point_cast<
      std::chrono::duration<int, std::ratio<86400>>>(td);
  auto now = td - td_days;
  auto h = std::chrono::duration_cast<std::chrono::hours>(now);
  now -= h;
  auto m = std::chrono::duration_cast<std::chrono::minutes>(now);
  now -= m;
  auto s = std::chrono::duration_cast<std::chrono::seconds>(now);
  now -= s;
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now);

  std::lock_guard<std::mutex> guard(_mutex);

  printf("(%02d:%02d:%02d.%03d) [%s]\b\t %s\n", (int)h.count(), (int)m.count(),
         (int)s.count(), (int)ms.count(), Log::LogLevelToText_(level).c_str(),
         text.c_str());
}

std::string Log::LogLevelToText_(enum LogLevel level) {
  std::string ans;
  switch (level) {
  case Log::LogLevel::info:
    return "\x1B[34mInfo\033[0m";
    break;
  case Log::LogLevel::warning:
    return "\x1B[33mWarning\033[0m";
    break;
  case Log::LogLevel::error:
    return "\x1B[31mError\033[0m";
    break;
  case Log::LogLevel::debug:
    return "\x1B[32mDebug\033[0m";
    break;
  case Log::LogLevel::memory:
    return "\x1B[35mMemory\033[0m";
    break;
  default:
    return "Unknown Type";
    break;
  }
}
} // namespace lg
