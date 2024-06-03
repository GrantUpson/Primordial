#ifndef PRIMORDIAL_LOGGER_H
#define PRIMORDIAL_LOGGER_H

#include <string>
#include <filesystem>


class Logger {
public:
    Logger() = default;
    ~Logger() = default;

    static void Log(const std::string& message, bool append = true);

private:
    static std::string GetCurrentDateTime();
};


#endif
