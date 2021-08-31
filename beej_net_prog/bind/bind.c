#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>

int main() {
    struct addrinfo hints, *res;
    int sockfd;

    // first load up address structs with getaddrinfo()
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;    // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;    // Auto-fill in my IP

    getaddrinfo(NULL, "3490", &hints, &res);    // if you want to specify an IP replace the NULL value

    // make a socket
    sockfd = socket(res -> ai_family, res -> ai_socktype, res -> ai_protocol);

    // bind it to the port passed into getaddrinfo()
    bind(sockfd, res -> ai_addr, res -> ai_addrlen);

    // if a socket is still in use but shouldn't be, you can try the below:
    int yes = 1;

    // clears the error message, 'Address already in use'
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1 ) {
        perror("setsockopt");
        exit(1);
    }
}
