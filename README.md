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
