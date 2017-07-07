// #include <iostream>
#include "server.h"
#include "config.h"
// #include <signal.h>
#include <iostream>

// int flag = 0;

// void catchInterrupt(int sig) {
//     flag = 1;
// }

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: http-server <config file>" << std::endl;
        return 1;
    }

    Config cfg = Config(argv[1]);
    Server s1 (&cfg);
    if (!s1.start()) {
        return 1;
    }
    s1.accept();
    return 0;
}
