#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>

int main() {
    struct addrinfo hints, *res;
    int sockfd;

    // load up address structs with getaddrinfo()
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("www.example.com", "443", &hints, &res);

    // make a socket
    sockfd = socket(res -> ai_family, res -> ai_socktype, res -> ai_protocol);

    // connect
    int status = connect(sockfd, res -> ai_addr, res -> ai_addrlen);
    printf("%i\n", h_errno);
    printf("%i\n",status);
}
