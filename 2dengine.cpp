// 2dengine.cpp: определяет точку входа для приложения.
//

#include "2dengine.h"
#include "logger.h"


int main() {

    Logger logger; logger.ClearFromFile();

    logger.Log(0, "This is a log message");
    logger.Log(1, "This is a warning message");
    logger.Log(2, "This is a error message");
    logger.Log(3, "Test");

    return 0;
}
