                     epoll_mode

This is a simple epoll() implementation for linux designer to use.


> Description

As man-pages describe that, epoll-  I/O event notification facility.
The "epoll_mode" is a simple implement for web server

The additional classes are listed as follow:

    1. future - A proxy object representing the basic set 

    2. IO-Buffer - A buffer I/O class to recieve and send data,
        This is designed to make dealing with recieved data significantly easier.

    3. TCPListenSocket - A listen socket that creates TCPSocket when some connection
        established. Provides an "valid connection" as callback.

    4. TCPSocket - A recieve and send buffering TCPSocket proxy,
        Provides recieve and disconnect callbacks.

> Dependencies

<sys/epoll.h> <br>
g++ std=c++11 <br>
gdb -used for debug <br>

