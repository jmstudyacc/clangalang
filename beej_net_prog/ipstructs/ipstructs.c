#include <stdio.h>
#include <arpa/inet.h>

/*
 * struct addrinfo {
    int ai_flags;    // AI_PASSIVE, AS_CANONNAME, etc.
    int ai_family;  // AF_INET, AF_INET6, AF_UNSPEC
    int ai_socktype;    // SOCK_STREAM, SOCK_DGRAM
    int ai_protocol;    // use 0 for "any"
    size_t ai_addrlen;  // size of ai_addr in bytes
    char *ai_canonname; // full canonical hostname
    struct sockaddr *ai_addr;   // struct sockaddr_in or _in6
    struct addr_info *ai_next;  // linked list, next node

};

struct sockaddr {
    unsigned short sa_family;   // address family, AF_xxx
    char sa_data[14];   // 14 bytes of protocol address - contains destination address and port number for the socket
};

struct in_addr {
    u_int32_t s_addr;   // an unsigned 32-bit int (4 bytes)
};

// A parallel struct is created to handle struct sockaddr, this is struct sockaddr_in ('in' for internet, for v4 use)
struct sockaddr_in {
    short int sin_family;   // Address family, AF_INET for IPv4
    unsigned short int sin_port;    // Port number - must be in Network Byte Order (via htons())
    struct in_addr  sin_addr;   // Internet address - reference to 4-byte Network Byte Order IP address
    unsigned char sin_zero[8];  // Same size as struct sockaddr - should be all 0s set by function memset()
};

struct in6_addr {
    unsigned char s6_addr[16];  // IPv6 address
};

// IPv6 version of the above
struct sockaddr_in6 {
    u_int16_t sin6_family;  // Address family, AF_INET6
    u_int16_t sin6_port;    // Port number in Network Byte Order
    u_int32_t sin6_flowinfo;    // IPv6 flow information
    struct in6_addr sin6_addr;  // IPv6 Address
    u_int32_t sin6_scope_id;    // Scope ID
};

// A structure designed to hold both IPv4 and IPv6 structures
struct sockaddr_storage {
    sa_family_t ss_family;  // Address family, use the AF_INET value here to determine type and cast to the appropriate sockaddr_in
    // below is padding, not relevant for this project
    char __ss_pad1[_SS_PAD1SIZE];
    int64_t __ss_align;
    char __ss_pad2[_SS_PAD2SIZE];
};
 */

int main() {
    struct sockaddr_in sa;  // Declaring an IPv4 address to be used in this example
    struct sockaddr_in6 sa6;    // Declaring an IPv6 address to be used in this example

    // Following will convert string IP addresses to binary formats - pton() is key
    inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr)); // IPv4 address converted to binary
    inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr)); // IPv6 address converted to binary

    // Following will do the reverse, convert a struct in_addr and print it in dotted decimal notation - ntop() is key
    char ip4[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);
    printf("The IPv4 address is: %s\n", ip4);

    char ip6[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &(sa6.sin6_addr), ip6, INET6_ADDRSTRLEN);
    printf("The IPv6 address is: %s\n", ip6);

    return 0;
}
