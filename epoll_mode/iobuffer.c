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
#include"iobuffer.h"

using std::string;

int buffer::getSizeOfBufferRecieved() const{
    return sizeOfBufferRecieved;
}

int buffer::getSizeOfBufferSend() const{
    return sizeOfBufferSend;
}

char* buffer::getBufferRecieved() const{
    return bufferRecieved;
}

char* buffer::getBufferSend() const{
    return bufferSend;
}

void buffer::redirectBufToFile(string filePath = "./store.txt"){
    int fd;     //  file descriptor
    //struct timeval timeOfWriting;   //  Time of file writing 
    if((fd = ::open(filePath.c_str(), O_WRONLY, O_CREAT | O_APPEND | O_NONBLOCK)) == -1){
        // If the file doesn't exist, creating it direct,
        // If the file exists, appending the content of buffer to the file.
        // Setting the mode of open as non-block.
        perror("redirectBufToFile open failed.\n");
        return;
    }
    
    if(write(fd, (void*)getBufferRecieved(), getSizeOfBufferRecieved()) == -1){
        //  Write failed
        perror("redirectBufToFile write failed.\n");
    }
}

void buffer::redirectBufToScreen(){
    if(write(STDOUT_FILENO, (void*)bufferRecieved, strlen(bufferRecieved)) == -1){
        //  write failed
        perror("redirectBufToScreen write failed.\n");
    }        
}
