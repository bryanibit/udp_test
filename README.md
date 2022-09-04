# UDP example

In UDP communication, there is accually no server or client.  
A computer **binds** its own port and use recvfrom(), the others computer just sendto the computer **IP and port** without bind().

## server (recvfrom)

1. initialize a socket
2. bind its own port and IP(INADDR_ANY)
3. recvfrom via its own port(can get clientaddr)

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

You can use `lsof -i:port` in client PC to verify if the port output from server.cc is consistent.
