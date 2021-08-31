//
// Created by James Miles on 31/08/2021.
//
/*
 * You may not be writing to connect to remote hosts, you may be writing to handle remote connections inbound to you
 * listen() is the way you approach this and using another function, like accept().
 *
 * int listen(int sockfd, int backlog)
 *
 * backlog, is the number of connections allowed on the incoming queue. Listen returns -1 and sets errno on an error.
 *
 * You need to have called bind() before you can listen as you need sockfd - server needs to run on a specific port!
 * If you intend to listen to incoming connections the sequence would be:
 *
 * 1) getaddrinfo();
 * 2) socket();
 * 3) bind();
 * 4) listen();
 * 5) accept()/reject()
 * */
