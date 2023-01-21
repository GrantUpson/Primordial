#include "Logger.h"

#include <chrono>
#include <fstream>


void Logger::Log(const std::string& message, bool append) {
    std::ofstream logFile;

    if(append) {
        logFile.open(std::filesystem::current_path().string() + "\\Log\\log.txt", std::ios_base::app);
    } else {
        logFile.open(std::filesystem::current_path().string() + "\\Log\\log.txt");
    }

    logFile << GetCurrentDateTime() + ": " + message + "\n";
    logFile.close();
}


std::string Logger::GetCurrentDateTime() {
    auto const time = std::chrono::current_zone() -> to_local(std::chrono::system_clock::now());
    return std::format("{:%d-%m-%Y %X}", time);
}


