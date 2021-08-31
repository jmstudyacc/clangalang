//
// Created by James Miles on 31/08/2021.
//

/*
 * int shutdown(int sockfd, int how)
 *
 * how - 0 = Further receives disallowed
 * how - 1 = Further sends are disallowed
 * how - 2 = Further sends and received are disallowed
 *
 * Remember, shutdown() doesn't CLOSE the file descriptor, it will not free up the socket descriptor. You need close()
 * for that.
 * */

int main(void)
{
    close(sockfd);  // this will prevent reads and writes to the socket - any attempts to do so will be met by an error
    shutdown(sockfd)    // this changes the socket usability and achieved via int how value
}