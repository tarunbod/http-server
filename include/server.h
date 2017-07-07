#ifndef SERVER_H
#define SERVER_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include "config.h"

class Server {

private:
    Config* config;
    int port;
    std::string workingDirectory;
    int sockfd;
    struct sockaddr_in address;
public:
    Server(Config* config);
    bool start();
    void accept();
};

#endif
