#ifndef SERIAL_LOGGER_H
#define SERIAL_LOGGER_H

#include <Arduino.h>
#include <ILogger.h>

class SerialLogger final : public ILogger {
public:
  explicit SerialLogger(
      Print& output,
      LogLevel minimumLevel = LogLevel::Info);

  void SetMinimumLevel(LogLevel level);

  void Log(
      LogLevel level,
      const char* source,
      const char* message) override;

private:
  Print& output;
  LogLevel minimumLevel;

  static const char* LevelName(LogLevel level);
};

#endif