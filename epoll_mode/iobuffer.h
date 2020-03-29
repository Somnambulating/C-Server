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

#ifndef EPOLL_MODE_IOBUFFER_H_
#define EPOLL_MODE_IOBUFFER_H_

//#include<vector>
#include<unistd.h>
#include<string>
#include<fcntl.h>
#include<memory>
#include<error.h>
//#include<sys/time.h>
//#include<time.h>
#include<string.h>

using std::string;
//using std::vector;

const int defaultBufSize = 256;     //  The size of buffer in default

class buffer{
private:
    int sizeOfBufferRecieved;
    int sizeOfBufferSend;
    char *bufferRecieved;
    char *bufferSend;

public:
    buffer(int rBufSize = defaultBufSize, int sBufSize = defaultBufSize):sizeOfBufferRecieved(rBufSize), sizeOfBufferSend(sBufSize){
        bufferRecieved = new char(sizeOfBufferRecieved);
        bufferSend = new char(sizeOfBufferSend);
    }
    int getSizeOfBufferRecieved() const;        //  Return sizeOfBufferRecieved
    int getSizeOfBufferSend() const;        //  Return sizeOfBufferSend
    void redirectBufToFile(string filePath);           //  Output content of buffer to file
    void redirectBufToScreen();         //  Output content of buffer to screen
    char *getBufferRecieved() const;       //  Return address of bufferRecieved
    char *getBufferSend() const;      //  Return address of bufferSend
    virtual ~buffer(){
        delete bufferRecieved;
        delete bufferSend;
    }
};

#endif
