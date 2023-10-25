#pragma once

#include <iostream>
#include <string>

class Logger {
public:
    void Log(const std::int8_t type, const std::string& message);
    void SaveToFile(const std::string& message);
    void ClearFromFile();
};