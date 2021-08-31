//
// Created by James Miles on 31/08/2021.
//

#include <sys/socket.h>
#include <netdb.h>
#include <printf.h>

int main() {
    int s;
    struct addrinfo hints, *res;

    // do the lookup - assume that 'hints' has already been filled in
    getaddrinfo("www.example.com", "http", &hints, &res);

    // you should do error checking when you run getaddrinfo() and walk the res linked-list
    // you should be checking for valid entries instead of just assuming the first is good
    s = socket(res -> ai_family, res -> ai_socktype, res -> ai_protocol);
    printf("%i", s);
}

