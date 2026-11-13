#include "SerialLogger.h"

SerialLogger::SerialLogger(
    Print& output,
    LogLevel minimumLevel)
    : output(output),
      minimumLevel(minimumLevel) {
}

void SerialLogger::SetMinimumLevel(LogLevel level) {
  minimumLevel = level;
}

void SerialLogger::Log(
    LogLevel level,
    const char* source,
    const char* message) {

  // Off disables logging and cannot be submitted as an event.
  if (minimumLevel == LogLevel::Off ||
      level == LogLevel::Off) {
    return;
  }

  // Include messages at or above the configured minimum.
  if (static_cast<uint8_t>(level) <
      static_cast<uint8_t>(minimumLevel)) {
    return;
  }

  output.print('[');
  output.print(LevelName(level));
  output.print(F("] ["));
  output.print(source != nullptr ? source : "");
  output.print(F("] "));
  output.println(message != nullptr ? message : "");
}

const char* SerialLogger::LevelName(LogLevel level) {
  switch (level) {
    case LogLevel::Debug:
      return "DEBUG";

    case LogLevel::Info:
      return "INFO";

    case LogLevel::Warning:
      return "WARNING";

    case LogLevel::Error:
      return "ERROR";

    case LogLevel::Off:
      return "OFF";
  }

  return "UNKNOWN";
}