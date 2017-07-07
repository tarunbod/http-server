#include "server.h"
#include "debug.h"

Server::Server(Config* config) {
    this->config = config;
    port = config->getInt("port");
    workingDirectory = config->getString("workingDirectory");
}

bool Server::start() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
        return false;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        error("ERROR on binding");
        return false;
    }
    listen(sockfd, 5);
    log("Server listening");
    return true;
}

void Server::accept() {
    struct sockaddr_in cli_addr;
    char buffer[1024];
    socklen_t cli_len = sizeof(cli_addr);
    int cli_sockfd = ::accept(sockfd, (struct sockaddr*) &cli_addr, &cli_len);
    if (cli_sockfd < 0) {
        error("Error on accept");
        close(cli_sockfd);
        close(sockfd);
        return;
    }
    int n = read(cli_sockfd, buffer, 1024);
    if (n < 0) {
        error("Error reading from socket");
        close(cli_sockfd);
        close(sockfd);
        return;
    }
    debug("Message received:");
    debug(buffer);

    std::string responseString = "HTTP/1.1 200 OK\r\nServer: CHTTP/1.0\r\nContent-Type: text/html\r\n\r\nHello, World!";
    const char* response_buffer = responseString.c_str();
    send(cli_sockfd, response_buffer, strlen(response_buffer), 0);
    close(cli_sockfd);
    close(sockfd);
}
