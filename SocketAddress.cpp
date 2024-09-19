/* this class is responsible for holding the ip address and port numbre that ServerSocket will use*/

#include<iostream>

#include<string>
class SocketAddress {
private:
    std::string address;
    int port;

public:
    SocketAddress();
    // Constructor
    SocketAddress(const std::string& addr, int prt) : address(addr), port(prt) {}

    // Getters
    std::string getAddress() const { return address; }
    int getPort() const { return port; }

    // Setters
    void setAddress(const std::string& addr) { address = addr; }
    void setPort(int prt) { port = prt; }

    // Additional method
    std::string toString() const {
        return address + ":" + std::to_string(port);
    }
};
