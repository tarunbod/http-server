#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <time.h>
#include <string>

#define BRIGHT_RED    "\e[91m"
#define BRIGHT_GREEN  "\e[92m"
#define BRIGHT_YELLOW "\e[93m"
#define RESET         "\e[0m"

void log(std::string msg);
void debug(std::string msg);
void error(std::string msg);

#endif
