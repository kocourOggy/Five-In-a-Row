#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <cstdio>
#include <ctime>

#include "Coordinate.h"
#include "constants.h"

//*****************************************************************

class Client
{
public:
   /** Constructor*/
   Client();
   /** Destructor*/
   ~Client();

   /**Set client port and client itselfs*/
   void setClient();

   /**Connect to server
   * @param[in] server IP adress
   * @param[in] server port where is listening */
   void connectToServer(const std::string & host, const std::string & port);

   /**Method for closing connection with server */
   void closeConnection();

   /**Method for receiving data */
   Coordinate listenCoor();
   /**Method for sending data */
   void sendCoor(const Coordinate & coordinate);

protected:
   
   /**Client socket */
   int m_MySocket;

   /**Receiving buffer*/
   char m_BuffName[BUFSIZE1];
   /**Sending buffer*/
   int m_BuffCoor[BUFSIZE2];
   /**Size of recv/send data*/  
   int m_SizeData;         

   
   /**Ip adress distant computer */
   hostent *m_Host; 
   /**struct sockaddr_in for server where we connect */
   sockaddr_in m_ServerSock;
   /**number of server port */
   int m_Port;
};

#endif /* __CLIENT_H__ */