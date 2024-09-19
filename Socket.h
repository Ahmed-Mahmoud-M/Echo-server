#ifndef E85255F8_2B93_4E42_AE91_29BDE07B014B
#define E85255F8_2B93_4E42_AE91_29BDE07B014B

#include <iostream>
#include <winsock2.h>
/*  this class will be a base class that
    serversocket and clientsocket will 
    inhernt from it  (these methods are common between the two)*/

class socket
{


public:
   
//    virtual int createSocket() = 0;
//    virtual int closeSocket() = 0;
//    virtual int send(int values)=0;
//    virtual int recieve()=0;


   virtual int wsaStartup(){
        // Initialize WSA variables
    WSADATA wsaData;
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaerr = WSAStartup(wVersionRequested, &wsaData);

    // Check for initialization success
    if (wsaerr != 0) {
        std::cout << "The Winsock dll not found!" << std::endl;
        return 0;
    } else {
        std::cout << "The Winsock dll found" << std::endl;
        std::cout << "The status: " << wsaData.szSystemStatus << std::endl;
    }

    return 1;
   }

};




#endif /* E85255F8_2B93_4E42_AE91_29BDE07B014B */
