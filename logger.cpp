#include "logger.h"
#include "colorswin.h"
#include <fstream>
#include <ctime>

Colors color;
const std::string FILENAME = ".log";

void Logger::Log(const std::string& message) {
    color.set_color(CL_WHITE);
    std::cout << "[Log] " << message << std::endl;
    SaveToFile("[Log] " + message);
}

void Logger::Error(const std::string& message) {
    color.set_color(CL_RED);
    std::cerr << "[Error] " << message << std::endl;
    SaveToFile("[Error] " + message);
    color.set_color(CL_WHITE);
}

void Logger::Warning(const std::string& message) {
    color.set_color(CL_YELLOW);
    std::cout << "[Warning] " << message << std::endl;
    SaveToFile("[Warning] " + message);
    color.set_color(CL_WHITE);
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