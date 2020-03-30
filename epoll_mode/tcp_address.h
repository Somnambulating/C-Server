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

#ifndef EPOLL_MODE_TCP_ADDRESS_H_
#define EPOLL_MODE_TCPSOCKET_H_

#include<sys/socket.h>
#include<arpa/inet.h>

class Address{
public:
    //  struct sockaddr_in defined in netinet/in.h
    /* Structure describing an Internet socket Address.  */
    struct sockaddr_in serverAddress;

public:
    explicit Address(){
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    explicit Address(int port){
    //  htons, htonl are inclued in netinet/in.h    
/* Functions to convert between host and network byte order.

   Please note that these functions normally take `unsigned long int' or
   `unsigned short int' values as arguments and also return them.  But
   this was a short-sighted decision since on different systems the types
   may have different representations but the values are always the same.
*/
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(port);
        serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    int getPort() const;      //  Return serverAddress.port
    long getAddress() const;        //  Return serverAddress.sin_addr.s_addr
    void resetPort(int port);        //  Reset the port
};

#endif
