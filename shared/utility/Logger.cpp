#include "Logger.h"

#include <chrono>
#include <fstream>


void Logger::Log(const std::string& message, bool append) {
    std::ofstream logFile;

    if(append) {
        logFile.open(std::filesystem::current_path().string() + "/Log/log.txt", std::ios_base::app);
    } else {
        logFile.open(std::filesystem::current_path().string() + "/Log/log.txt");
    }

    logFile << GetCurrentDateTime() + message + "\n";
    logFile.close();
}


std::string Logger::GetCurrentDateTime() {
    auto currentTime = std::chrono::system_clock::now();
    time_t convertedTime = std::chrono::system_clock::to_time_t(currentTime);
    char formattedTime[23];
    strftime(formattedTime, 23, "%d-%m-%Y %H:%M:%S | ", localtime(&convertedTime));
    return formattedTime;
}


