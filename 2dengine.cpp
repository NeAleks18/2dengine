// 2dengine.cpp: определяет точку входа для приложения.
//

#include "2dengine.h"
#include <fstream>

using namespace std;
#include "logger.h"


int main() {

    Logger logger; logger.ClearFromFile();

    logger.Log("This is a log message");
    logger.Error("This is an error message");
    logger.Warning("This is a warning message");

    return 0;
}
