#include "logger.h"
#include <fstream>
#include <ctime>

#ifdef __linux__
// Код для Linux
const std::string FILENAME ="logs.log";
#else
#include "colorswin.h"
Colors color;
const std::string FILENAME = ".log";
#endif

void Logger::Log(const std::string& message) {
#ifdef __linux__
    // Код для Linux
#else
    color.set_color(CL_WHITE);
#endif

    std::cout << "[Log] " << message << std::endl;
    SaveToFile("[Log] " + message);
}

void Logger::Error(const std::string& message) {
#ifdef __linux__
    // Код для Linux
#else
    color.set_color(CL_RED);
#endif

    std::cerr << "[Error] " << message << std::endl;
    SaveToFile("[Error] " + message);

#ifdef __linux__
    // Код для Linux
#else
    color.set_color(CL_WHITE);
#endif
}

void Logger::Warning(const std::string& message) {
#ifdef __linux__
    // Код для Linux
#else
    color.set_color(CL_YELLOW);
#endif

    std::cout << "[Warning] " << message << std::endl;
    SaveToFile("[Warning] " + message);

#ifdef __linux__
    // Код для Linux
#else
    color.set_color(CL_WHITE);
#endif
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