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
int main(){
    int mSocket;
    if ((mSocket = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
		std::cout << "Setup socket error." << std::endl;
    struct sockaddr_in Socketaddr;
    // string CONF_VEHICLE_IP_ADDRESS = "127.0.0.1";
	// bzero(&Socketaddr.sin_zero), sizeof(struct sockaddr_in));
	Socketaddr.sin_family = AF_INET;
	Socketaddr.sin_port = htons(10012);
	Socketaddr.sin_addr.s_addr = htonl(INADDR_ANY);//inet_addr(CONF_VEHICLE_IP_ADDRESS.c_str()); 
    if (bind(mSocket, (struct sockaddr *)&Socketaddr, sizeof(struct sockaddr)) == -1){
		std::cout << "bind mSocket failed!" << std::endl;
		std::cout << "\n" << std::endl;
	}
    char buf[1024] = {0};
    struct sockaddr_in clientaddr;
    socklen_t clientaddr_len = sizeof(clientaddr);
    while(true){
        int recvlen = recvfrom(mSocket,buf, 1024, 0, (struct sockaddr*)&clientaddr, &clientaddr_len);
        string str(buf);
        std::cout << "recv size: " << recvlen << ": " << str << std::endl;
        bzero(buf, sizeof(buf));
    }
    return 0;
}