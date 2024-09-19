#ifndef E85255F8_2B93_4E42_AE91_29BDE07B014B
#define E85255F8_2B93_4E42_AE91_29BDE07B014B


/*  this class will be a base class that
    serversocket and clientsocket will 
    inhernt from it */

class socket
{


public:
   virtual int wsaStartup() = 0;
   virtual int createSocket() = 0;
   virtual int closeSocket() = 0;
   virtual int connect() = 0;
   virtual int send(auto values) = 0;
   virtual auto recieve() = 0;

};




#endif /* E85255F8_2B93_4E42_AE91_29BDE07B014B */
