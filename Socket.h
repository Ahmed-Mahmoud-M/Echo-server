#ifndef E85255F8_2B93_4E42_AE91_29BDE07B014B
#define E85255F8_2B93_4E42_AE91_29BDE07B014B

#include <iostream>
#include<string>
#include <winsock2.h>
/*  this class will be a base class that
    serversocket and clientsocket will 
    inhernt from it  (these methods are common between the two)*/

class Socket
{


public:
   




   virtual int wsaStartup(){
        // Initialize WSA variables

        WORD wversionRequested = MAKEWORD(2,2);
        WSADATA wsaData;
        int wsaerr =0;

        wsaerr = WSAStartup(wversionRequested,&wsaData);
        if (wsaerr!=0) {
            std::cout << "WSA dll not found" << std::endl;
            return 1;
        }else{
            std::cout << "WSA dll initialized" << std::endl;
            std::cout << "status :" <<wsaData.szSystemStatus << std::endl;
        }

        return 0;   
   }

      virtual SOCKET createSocket() {
        SOCKET newsocket = INVALID_SOCKET;

        newsocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
        if(newsocket == INVALID_SOCKET) {
            std::cout <<"failed to create socket" << std::endl;
            WSACleanup();
        }else{
            std::cout << "socket created createsocket() " << std::endl;
        }
    

        return newsocket;

      }


        virtual int CloseSocket(SOCKET socket){
          int  x =  closesocket(socket);
            if (x == 0) {
                std::cout << "socket closed" << std::endl;
                return 0;
            }
            return -1;
        }


   
    virtual int  sendData(SOCKET socket){
        char * data = "";
        std::cin.getline(data,sizeof(data));
        int bytecount = send(socket,data,sizeof(data),0);
        if (bytecount == SOCKET_ERROR) {
            std::cout << "server error %d" << WSAGetLastError()<< std::endl;

        }else{
            std::cout << "server sent data : %d bytes"<<sizeof(data) <<std::endl;
        }

    }
   virtual int receiveData(SOCKET socket){
        char * data = "";
        std::cin.getline(data,sizeof(data));
        int bytecount = recv(socket,data,sizeof(data),0);
        if (bytecount <0) {
            std::cout << " error %d" << WSAGetLastError()<< std::endl;
            return 1;

        }else{
            std::cout << " recieved data : %d "<<data <<std::endl;
        }

            return 0;
   }

};

// Define struct socketAddress
struct socketAddress {
    std::string ipaddress;
    int port;

    void displayInfo() {
        std::cout << "IP Address: " << ipaddress << ", Port: " << port << std::endl;
    }
};







#endif /* E85255F8_2B93_4E42_AE91_29BDE07B014B */
