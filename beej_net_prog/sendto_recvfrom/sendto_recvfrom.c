//
// Created by James Miles on 31/08/2021.
//

/*
 * Here's an example of the sendto() function for datagrams:
 *
 * int sendto(int sockfd, const void *msg, int len, unsigned int flags, const struct sockaddr *to, socklen_t tolen)
 *
 * This is similar to send() but with the addition of '*to' and 'tolen'.
 *
 * *to = pointer to a struct sockaddr (likely another struct e.g sockaddr_in) which contains destination IP address and port
 * tolen = an integer that is set to sizeof *to
 *
 * Acquiring the destination address structure will require info from getaddrinfo() or from recvfrom() below.
 * Similar to send(), sendto() returns the number of bytes actually sent, or -1 errno.
 *
 * recvfrom() is very similar to recv():
 *
 * int recvfrom(int sockfd, void *buf, int len, int flags, struct sockaddr *from, int *fromlen);
 *
 * *from = a pointer to a local struct sockaddr_storage that will contain the IP address and port of the source machine
 * *fromlen = a pointer to a local int that is initialized to the sizeof(struct sockaddr_storage).
 *
 * This returns the number of bytes received, or -1 errno.
 *
 * If you connect() a datagram socket, you can then just use send() and recv() for the transactions. The socket will
 * remain a datagram socket using UDP, but the socket interface will automatically add the destination and source info.
 * */