#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <string>
#include <map>
#include "debug.h"

/**
 * Reads config files in the following format:
 *  key=value
 * Basically java's .properties format
 */
class Config {
private:
    std::map<std::string, std::string> values;
public:
    Config(std::string = "~/.http-server.cfg");
    std::string getString(std::string key);
    int getInt(std::string key);
    // void write();
};

#endif // CONFIG_H
