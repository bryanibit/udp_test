#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <string.h>
using namespace std;
/*
 * client needs to initialize a socket but not need to name the socket(socket no need to bind()).
 * client sendto() destination addr, which needs dest's IP and port(server's IP and port)
*/
int main(){
    int mSocket;
    string CONF_VEHICLE_IP_ADDRESS = "192.168.1.126";
    if ((mSocket = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
		std::cout << "Setup socket error." << std::endl;
    // struct sockaddr_in Socketaddr;
	// // bzero(&Socketaddr.sin_zero), sizeof(struct sockaddr_in));
	// Socketaddr.sin_family = AF_INET;
	// Socketaddr.sin_port = htons(10012);
	// Socketaddr.sin_addr.s_addr = htonl(INADDR_ANY);//inet_addr(CONF_VEHICLE_IP_ADDRESS.c_str());
    // if (bind(mSocket, (struct sockaddr *)&Socketaddr, sizeof(struct sockaddr)) == -1){
	// 	std::cout << "bind mSocket failed!" << std::endl;
	// 	std::cout << "\n" << std::endl;
	// }
    char buf[1024];
    struct sockaddr_in serveraddr;
    socklen_t serveraddr_len = sizeof(serveraddr);
    // bzero(&serveraddr, serveraddr_len);
    serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(10012);
	serveraddr.sin_addr.s_addr = inet_addr(CONF_VEHICLE_IP_ADDRESS.c_str());
    for(int i = 0; i < 1000; i ++){
        sprintf(buf, "This is packet %d", i);
        int len = sendto(mSocket, buf, strlen(buf), 0, (struct sockaddr *)&serveraddr, serveraddr_len);
        string str(buf);
        std::cout << "send: " << str << std::endl;
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(100ms);
    }
    return 0;
}
