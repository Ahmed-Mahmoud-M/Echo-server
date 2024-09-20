#include<iostream>

#include "ServerSocket.cpp"
#include "ClientSocket.cpp"







int main(int argc, char const *argv[])
{
   
    socketAddress sockaddress ={"127.0.0.1",  200};
    // ServerSocket server(sockaddress);
    // server.displayServerInfo();

    // server.run();


    ClientSocket client = ClientSocket(sockaddress);
    client.run();

    

    
    
    return 0;
}
