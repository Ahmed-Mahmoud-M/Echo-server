#include<iostream>

#include "ServerSocket.cpp"







int main(int argc, char const *argv[])
{
   
    socketAddress sockaddress ={"127.0.0.1",  200};
    ServerSocket server(sockaddress);
    server.displayServerInfo();

    

    
    
    return 0;
}
