#include <iostream>
#include <string>
#include "Socket.h"



class ClientSocket : public Socket {
public:
    socketAddress serverAddress; // Server's IP address and port
    int clientSocket;            // Socket descriptor
    bool isConnected;            // Connection status

    ClientSocket();
    ClientSocket(const socketAddress& addr);
  

    int connectToServer(SOCKET socket);
    
    void displayClientInfo();
    SOCKET createClientSocket();
    void run ();


};

// Implement the constructors
ClientSocket::ClientSocket() : clientSocket(-1), isConnected(false) {}

ClientSocket::ClientSocket(const socketAddress& addr) : serverAddress(addr), clientSocket(-1), isConnected(false) {}


int ClientSocket::connectToServer(SOCKET socket) {
    
    isConnected = true; 
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(this->serverAddress.port);
   
    service.sin_addr.s_addr = inet_addr(this->serverAddress.ipaddress.c_str());


    int connected = connect(socket,reinterpret_cast<SOCKADDR*>(&service),sizeof(service));
        if (connected == SOCKET_ERROR) {
            std::cout << "connect socket error" << WSAGetLastError()<< std::endl;
            CloseSocket(socket);
            WSACleanup();
            return -1;
        }else{
               std::cout<< "connect() is ok"<< std::endl;
               std::cout<< "client can send and receive"<< std::endl;
        }
            return 0;
    return 0;
}



void ClientSocket::displayClientInfo() {
}



void ClientSocket::run(){
    wsaStartup();
   SOCKET newsocket = createSocket();
    connectToServer(newsocket);
    


}




int main(int argc, char const *argv[]) {
    socketAddress sockaddress = {"192.168.1.73", 5555};
    ClientSocket client(sockaddress);
    client.run();
    return 0;
    
}
