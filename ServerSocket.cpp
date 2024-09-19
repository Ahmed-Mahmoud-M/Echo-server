#include <iostream>
#include <string>

// Define struct socketAddress first
struct socketAddress {
    std::string ipaddress;
    int port;

    void displayInfo() {
        std::cout << "IP Address: " << ipaddress << ", Port: " << port << std::endl;
    }
};

class ServerSocket {
public:
    socketAddress sockaddr;
    ServerSocket(); // Default constructor
    ServerSocket(const socketAddress& addr); // Parameterized constructor
    ~ServerSocket();

    int bindsocket();
    int listnForConnections();
    int acceptConnection();
    void displayServerInfo();
};

// Implement the constructors
ServerSocket::ServerSocket() : sockaddr({"", 0}) {} // Initialize sockaddr with default values

ServerSocket::ServerSocket(const socketAddress& addr) : sockaddr(addr) {} // Correct initialization

ServerSocket::~ServerSocket() {} // Add destructor implementation if needed

void ServerSocket::displayServerInfo() {
    sockaddr.displayInfo();
}

// Implement other methods (bindsocket, listnForConnections, acceptConnection)
int ServerSocket::bindsocket() {
    // Implementation of bindsocket
    return 0;
}

int ServerSocket::listnForConnections() {
    // Implementation of listnForConnections
    return 0;
}

int ServerSocket::acceptConnection() {
    // Implementation of acceptConnection
    return 0;
}
