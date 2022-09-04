# UDP example

In UDP communication, there is accually no server or client.  
A computer binds its own port and recvfrom, the others just sendto the computer IP and port without bind().

## server (recvfrom)

1. initialize a socket
2. bind its own port and IP(INADDR_ANY)
3. recvfrom a client addr via its own port

## client (sendto)

1. initialize a socket
2. assign server IP and port
3. sendto the above server IP and port

# use

In a PC whose IP is 192.168.1.126, run
```sh
g++ server.cc -o server
./server
```

In a PC whose IP is another, run
```sh
g++ client.cc  -o client -std=c++14 -pthread
./client
```
