/*
 * Copyright 2020 Descosmos  
 *
 * All rights reserved.
 *
 * Redistribution and use in source, with or without 
 * modification, are permitted provided that following coditions:
 *
 *  1. Nither the name of copyright holders nor names of its 
 *      contributors may be used to endorse or promote products 
 *      derived from thise software without specific prior written 
 *      permission.
 *
 *  2. Whatever the way contributors want to modify the code, 
 *      it's doesn't care about the original copyright.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS.
 *
 * */

#ifndef EPOLL_MODE_TCPSOCKET_H_
#define EPOLL_MODE_TCPSOCKET_H_

#include"tcp_address.h"
#include<string.h>
class Socket{
private:
    int conncFd;        //  Restore the value from socket
    Address address;      // Address of server
    int _maxFd;     //  The second argc of listen
public:
    explicit Socket(){
        conncFd = 0;
    }
    /*Create a new socket of type AF_INET*/
    int socket();
    
    /* Give the socket FD the local address ADDR (which is LEN bytes long).  */
    int bind();

    /*Prepare to accept connections on socket conncFd*/
    int listen(int _maxFd);

    /*Get the second argc of tcp listen*/
    int getBacklog() const;
};

#endif
