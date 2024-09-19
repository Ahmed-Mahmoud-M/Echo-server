#include <iostream>
#include <string>
#include <iostream>
#include <string>

// Define struct socketAddress
struct socketAddress {
    std::string ipaddress;
    int port;

    void displayInfo() {
        std::cout << "IP Address: " << ipaddress << ", Port: " << port << std::endl;
    }
};

class ClientSocket {
public:
    socketAddress serverAddress; // Server's IP address and port
    int clientSocket;            // Socket descriptor
    bool isConnected;            // Connection status

    ClientSocket();
    ClientSocket(const socketAddress& addr);
    ~ClientSocket();

    int connectToServer();
    int sendData(const std::string& data);
    int receiveData(std::string& buffer);
    void displayClientInfo();

private:
    void closeConnection();
};

// Implement the constructors
ClientSocket::ClientSocket() : clientSocket(-1), isConnected(false) {}

ClientSocket::ClientSocket(const socketAddress& addr) : serverAddress(addr), clientSocket(-1), isConnected(false) {}

ClientSocket::~ClientSocket() {
    if (isConnected) {
        closeConnection();
    }
}

int ClientSocket::connectToServer() {
    
    isConnected = true; // Set to true if successful
    return 0;
}

int ClientSocket::sendData(const std::string& data) {
    // Implementation of sendData
    return 0;
}

int ClientSocket::receiveData(std::string& buffer) {
    // Implementation of receiveData
    return 0;
}

void ClientSocket::displayClientInfo() {
}

void ClientSocket::closeConnection() {
    // Implementation of closing the socket
    isConnected = false;
}



