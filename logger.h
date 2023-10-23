#pragma once

#include <iostream>
#include <string>

class Logger {
public:
    void Log(const std::string& message);
    void Error(const std::string& message);
    void Warning(const std::string& message);
    void SaveToFile(const std::string& message);
    void ClearFromFile();
};