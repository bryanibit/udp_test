#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
server needs bind() its own port
recvfrom() clientaddr; no need to know its IP or port,
if recvfrom() succeeds, clientaddr and port is known
*/
int main(){
    int mSocket;
    bool flag = false;
    if ((mSocket = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
		std::cout << "Setup socket error." << std::endl;
    struct sockaddr_in Socketaddr;
    string CONF_VEHICLE_IP_ADDRESS = "192.168.1.126";
	// bzero(&Socketaddr.sin_zero), sizeof(struct sockaddr_in));
	Socketaddr.sin_family = AF_INET;
	Socketaddr.sin_port = htons(10012);
	Socketaddr.sin_addr.s_addr = htonl(INADDR_ANY); // inet_addr(CONF_VEHICLE_IP_ADDRESS.c_str());
    if (bind(mSocket, (struct sockaddr *)&Socketaddr, sizeof(struct sockaddr)) == -1)
		std::cout << "bind mSocket failed!" << std::endl;
    char buf[1024] = {0};
    struct sockaddr_in clientaddr;
    socklen_t clientaddr_len = sizeof(clientaddr);
    while(true){
        int recvlen = recvfrom(mSocket,buf, 1024, 0, (struct sockaddr*)&clientaddr, &clientaddr_len);
        string str(buf);
        std::cout << "recv size: " << recvlen << ": " << str << std::endl;
        bzero(buf, sizeof(buf));
        if(!flag){
            std::cout << "\033[1;31mrecv data from " << inet_ntoa(clientaddr.sin_addr)
            << ":" << ntohs(clientaddr.sin_port) << "\033[0m\n";
            flag = true;
        }
    }
    return 0;
}
