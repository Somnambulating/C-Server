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

#ifndef EPOLL_MODE_EVENTMANAGER_H
#define EPOLL_MODE_EVENTMANAGER_H

#include<algorithm>
#include<thread>
#include<vector>
#include<memory>
#include<sys/epoll.h>
#include"tcp_socket.h"

/*  After the tcp connection has established, eventManager listens and 
 *  implement requests from client.
 *
 *  Watch on sockets and execute functions to deal with requests.
 * */
class eventManager{
private:
    struct epoll_event _event;
    struct epoll_event *_waitEvent;
    Socket _socket;
    int _epollSize;
    int _epollFd;
    int _maxEvents;
public:
    explicit eventManager(){
        _waitEvent = NULL;
        _epollSize = 0;
        _epollFd = 0;
        _maxEvents = 0;
    }

    virtual ~eventManager(){
        delete _waitEvent;
    }

    /*Creates an epoll instance.*/
    int epoll_create(int _size);

    /*Manipulate an epoll instance "epfd". */
    int epoll_ctl();

    /*Wait for events on an epoll instance "epfd". */
    int epoll_wait();

    /*Get epoll Size*/
    int getEpollSize() const;

    /*Get Maxnium num of epoll events.*/
    int getMaxEvents() const;
};


#endif
