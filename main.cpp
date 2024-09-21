#include<iostream>

#include "ServerSocket.cpp"
#include "ClientSocket.cpp"







int main(int argc, char const *argv[])
{
   
    socketAddress sockaddress ={"192.168.1.73",5555};
    // ServerSocket server(sockaddress);
    // server.displayServerInfo();

    // server.run();


    ClientSocket client = ClientSocket(sockaddress);
    client.run();

    

    
    
    return 0;
}
