//
// Created by James Miles on 31/08/2021.
//
/*
 * The send() call: int send(int sockfd, const void *msg, int len, int flags);
 *
 * sockfd = socket descriptor you want to send data to (either one returned by socket() or one got with accept())
 * *msg = a pointer to the data you want to send
 * len = length of that data in bytes
 * flags = can be set to 0 for simplicity
 *
 * A simple example:
 *
 * char *msg = "James is learning C";
 * int len, bytes_sent;
 *
 * len = strlen(msg);
 * bytes_sent = send(sockfd, msg, len, 0)
 *
 * The recv() call: int recv(int sockfd, void *buf, int len, int flags);
 *
 * sockfd = socket descriptor you want to read from
 * *buf = pointer to the buffer to read the information into
 * len = maximum length of the buffer
 * flags = can be set to 0 for simplicity
 *
 * recv() returns the number of bytes actually read into the bugger, or -1 in error (errno set)
 *
 * If the returned value to recv() = 0 that means the remote end has closed the connection.
 */
