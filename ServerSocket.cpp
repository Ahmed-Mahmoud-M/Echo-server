#include <iostream>
#include <string>
#include "Socket.h"



class ServerSocket :public Socket{
public:
    socketAddress sockaddr;
    ServerSocket(); // Default constructor
    ServerSocket(const socketAddress& addr); // Parameterized constructor
    ~ServerSocket();

    int bindsocket(SOCKET socket);
    int listnForConnections(SOCKET socket);
    int acceptConnection();
    void displayServerInfo();
   
    
    void run();
};

// Implement the constructors
ServerSocket::ServerSocket() : sockaddr({"", 0}) {} // Initialize sockaddr with default values

ServerSocket::ServerSocket(const socketAddress& addr) : sockaddr(addr) {} // Correct initialization

ServerSocket::~ServerSocket() {} // Add destructor implementation if needed

void ServerSocket::displayServerInfo() {
    sockaddr.displayInfo();
}

// Implement other methods (bindsocket, listnForConnections, acceptConnection)
int ServerSocket::bindsocket(SOCKET socket) {
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(this->sockaddr.port);
   
    service.sin_addr.s_addr = inet_addr(this->sockaddr.ipaddress.c_str());


    int binded = bind(socket,reinterpret_cast<SOCKADDR*>(&service),sizeof(service));
        if (binded == SOCKET_ERROR) {
            std::cout << "bind socket error" << WSAGetLastError()<< std::endl;
            CloseSocket(socket);
            WSACleanup();
            return -1;
        }else{
               std::cout<< "bind() is ok"<< std::endl;
        }
            return 0;
}

int ServerSocket::listnForConnections(SOCKET socket) {
  int islistening = listen(socket,1);

    if (islistening == SOCKET_ERROR) {
        std::cout << "listenig error" << WSAGetLastError()<< std::endl;
        return -1;
    }else{
        std::cout<< "listen() is ok" <<std::endl;
        return 0;
    }

    return 0;
}

int ServerSocket::acceptConnection() {
    // Implementation of acceptConnection
    return 0;
}





void ServerSocket::run() {
    wsaStartup();
    SOCKET newsocket = createSocket();
    bindsocket(newsocket);
    listnForConnections(newsocket);
}