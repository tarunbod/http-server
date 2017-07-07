#include "config.h"

Config::Config(std::string filename) {
    std::ifstream file (filename);
    if (!file.is_open()) {
        error("Opening file failed");
    } else {
        std::string line;
        while (!file.eof()) {
            std::getline(file, line);
            if (line.empty()) {
                continue;
            }
            std::string::size_type n = line.find("=");
            if (n == std::string::npos) {
                error("Error while reading config file");
                break;
            }
            std::string key = line.substr(0, n);
            std::string value = line.substr(n + 1);
            values.insert(std::pair<std::string, std::string>(key, value));
        }
    }
}

std::string Config::getString(std::string key) {
    auto ret = values.find(key);
    if (ret == values.end()) {
        return "";
    }
    return ret->second;
}

int Config::getInt(std::string key) {
    int val = std::stoi(Config::getString(key));
    return val;
}

// void Config::write() {
    // TODO
// }
