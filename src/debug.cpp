#include "debug.h"

void timestr(char* buffer) {
    time_t current;
    struct tm *timeinfo;

    time(&current);
    timeinfo = localtime(&current);
    strftime(buffer, 25, "[%D %T]: ", timeinfo);
}

void log(std::string msg) {
    std::cout << BRIGHT_GREEN << msg << RESET << std::endl;
}

void debug(std::string msg) {
    char buffer[25];
    timestr(buffer);
    std::cout << buffer << BRIGHT_YELLOW << msg << RESET << std::endl;
}

void error(std::string msg) {
    char buffer[25];
    timestr(buffer);
    std::cerr << buffer << BRIGHT_RED << msg << RESET << std::endl;
}
