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

#include"tcp_address.h"

int address::getPort() const{
    return ntohs(serverAddress.sin_port);
}

long address::getAddress() const{
    return ntohl(serverAddress.sin_addr.s_addr);
}
