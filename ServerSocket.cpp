//#include "socket.h"
#include <iostream>
#include <string>



class ServerSocket 
{
public:
  
    
    int bindsocket();
    int listnForConnections();
    int acceptConnection();
    void displayServerInfo();


};

ServerSocket::ServerSocket(){
    
    std::cout<< "Enter ServerSocket ip address : ";

}








void ServerSocket::displayServerInfo() {
        

}




struct socketAddress {
    std::string ipaddress;
    int port;

    
    void displayInfo() {
        std::cout << "IP Address: " << ipaddress << ", Port: " << port << std::endl;
    }
};






