//
// Created by James Miles on 31/08/2021.

// int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
//

#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MYPORT "3490"   // the port users will connect to
#define BACKLOG 10      // number of pending connections that will be held

int main(void)
{
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    struct addrinfo hints, *res;
    int sockfd, new_fd;

    // first load up address structs with getaddrinfo()
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;    // fill in IP for me

    getaddrinfo(NULL, MYPORT, &hints, &res);

    // make a socket, bind it and listen to it
    sockfd = socket(res -> ai_family, res -> ai_socktype, res -> ai_protocol);
    bind(sockfd, res -> ai_addr, res -> ai_addrlen);
    listen(sockfd, BACKLOG);

    // now accept the incoming connection
    addr_size = sizeof their_addr;
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);

    // communication is now available on socket descriptor new_fd
}