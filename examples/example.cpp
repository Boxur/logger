#include <chrono>
#include <lg/logger.hpp>
#include <thread>

int main() {
  lg::log.SetLevel((short)lg::Log::LogLevel::error);
  lg::log("Info log");
  lg::log(lg::Log::LogLevel::error, "Error log");

  // sleep for the log threads to come in
  std::this_thread::sleep_for(std::chrono::duration(std::chrono::seconds(1)));
  return 0;
}
