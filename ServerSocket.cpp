//#include "socket.h"
#include "SocketAddress.cpp"



class ServerSocket 
{


private:
    SocketAddress socketAddress;

public:
    ServerSocket();
    ServerSocket(const SocketAddress& socketAddress);
    int bindsocket();
    int listnForConnections();
    int acceptConnection();
    void displayServerInfo();


};

ServerSocket::ServerSocket(){}


ServerSocket::ServerSocket(const SocketAddress& address) : socketAddress(address) {

}




void ServerSocket::displayServerInfo() {
        std::cout << "Server is running at: " << socketAddress.toString() << std::endl;

}


