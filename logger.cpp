﻿#include "logger.h"
#include <fstream>
#include <ctime>

#ifdef __linux__
// Code for linux
const std::string FILENAME ="logs.log";
#else
const std::string FILENAME = ".log";
#endif
const std::string PREFIXs[] = {"[Log] ", "[Warning] ", "[Error] "};
const std::string COLORS[] = { "\x1B[37m", "\x1B[33m", "\x1B[31m" };

void Logger::Log(const std::int8_t type, const std::string& message) {
    
    std::cout << COLORS[type] << PREFIXs[type] << message << COLORS[0] << std::endl;
    SaveToFile(PREFIXs[type] + message);
}


void Logger::SaveToFile(const std::string& message) {
    std::ofstream outputFile(FILENAME, std::ios::app);
    if (outputFile.is_open()) {
        time_t currentTime = time(nullptr);
        std::string date = std::ctime(&currentTime);
        date.pop_back(); // Remove newline character
        outputFile << date << " " << message << std::endl;

        outputFile.close();
    }
}

void Logger::ClearFromFile() {
    std::ofstream outputFile(FILENAME, std::ios::trunc);
}