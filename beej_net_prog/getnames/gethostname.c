//
// Created by James Miles on 31/08/2021.
//

/*
 * This function returns the name of the computer that the program is running on.
 * This can then be used by gethostbyname() to determine the IP address of the local interface
 *
 * #include <unistd.h>
 *
 * int gethostname(char *hostname, size_t size);
 *
 * *hostname = a pointer to an array of chars that will contain the hostname upon the function return
 * size = the length in bytes of the hostname array
 *
 * Function returns 0 on successful completion and -1 on error & errno
 * */
