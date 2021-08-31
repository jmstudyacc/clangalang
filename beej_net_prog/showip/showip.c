/*
 * Created by James Miles on 22/08/2021.
 *
 * This quick demo program will show the information that is stored by the 'servinfo' linked-list.
 * This information will be addressing information of the interface IP passed to the function.
 * The information will be printed out to the command line.
 *
 * showip.c -- Prints out IP addresses for a host given on the command line.
 *
 * The code will pass whatever is passed by the command line to the getaddrinfo() function. This fills the linked-list
 * pointed to by res and then the linked-list is iterated over & printed against.
*/

#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main( int argc, char *argv[]){
    struct addrinfo hints, *res, *p;    // requires netdb.h import
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    if ( argc != 2) {
        fprintf(stderr, "Usage: showip hostname\n");    // fprintf & stderr requires stdio.h import
        return 1;
    }

    memset(&hints, 0, sizeof hints);    // memset is a macro that requires string.h import
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &res) != 0))
    {
        fprintf(stderr, "getadrrinfo: %s\n", gai_strerror(status));
        return 2;
    }

    printf("IP addresses for %s:\n\n", argv[1]);

    for ( p = res; p != NULL; p = p -> ai_next)
    {
        void *addr;
        char *ipver;

        // get the pointer to the address itself - different fields used in IPv4 and IPv6
        if ( p -> ai_family == AF_INET ) // IPv4 Addressing
        {
            struct sockaddr_in *ipv4 = ( struct sockaddr_in *) p -> ai_addr;
            addr = &(ipv4 -> sin_addr);
            ipver = "IPv4";
        } else {
            struct sockaddr_in6 *ipv6 = ( struct sockaddr_in6 *) p -> ai_addr;
            addr = &( ipv6 -> sin6_addr );
            ipver = "IPv6";
        }

        // Convert the IP address to a String and print it
        inet_ntop( p -> ai_family, addr, ipstr, sizeof ipstr);  // requires arpa/inet.h import
        printf("IP Version: %s\nIP Address: %s\n", ipver, ipstr);
    }

    freeaddrinfo(res);  // Frees the linked-list data structure used by 'res'

    return 0;
}
