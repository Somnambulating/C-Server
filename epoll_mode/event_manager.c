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
#include"event_manager.h"

int eventManager::epoll_create(int _size){
    _epollSize = _size;
    _epollFd = ::epoll_create(_size);
    return _epollFd;
}

int eventManager::epoll_ctl(){

}

int eventManager::epoll_wait(){}

int eventManager::getEpollSize() const{
    return _epollSize;
}

int eventManager::getMaxEvents() const{
    return _maxEvents;
}
