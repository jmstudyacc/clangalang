//
// Created by James Miles on 31/08/2021.
//

/*
Following acts a blueprint for using it:

#include <sys/socket.h>
int getpeername(int sockfd, struct sockaddr *addr, int *addrlen);

 sockfd = socket file descriptor of connected stream socket
 *addr = a pointer to a struct sockaddr (or struct sockaddr_in)
 *addrlen = pointer to an int that is initialized to sizeof *addr or sizeof(struct sockaddr)

 -1 and errno returned on failure

 Once you have the peer address you can inet_ntop(), getnameinfo(), gethostbyteaddr() to print or get
 more information
*/
