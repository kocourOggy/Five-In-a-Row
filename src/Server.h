#ifndef __SERVER_H__
#define __SERVER_H__

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

class Server
{
public:
   /** Constructor */
	Server();
   /** Destruktor */
	~Server();

   /** Set port and server for connection
   * @param[in] Server port */
   void setServer(const std::string & port);
  
   /** Method for sending coordinate moves
   * @param[in] struct Coordinate (row, col) */
	void sendCoor(const Coordinate & coordinate);

   /** Method for receiving coordinate moves*/
	Coordinate listenCoor();

   /** Method for ending connection*/
   void closeConnection();

   /** Method which wait for connection with client (server 'listen')*/
	void ReadytoConnect();

protected:

   /** Server socket*/
	int m_MainSocket;  

   /** Name of port */
   sockaddr_in m_SockName;  
   /**Number of port*/       
   int m_Port;             
   	
   /** receiving buffer*/
   char m_BuffName[BUFSIZE1];  
   /** sending buffer*/
   int m_BuffCoor[BUFSIZE2];
   /** size of receiving/sending data */
   int m_SizeData;



	/** Client socket*/
   	int m_Client; 
   /** Client which is connected*/
   	sockaddr_in m_ClientInfo; 
   /** Size of adress distant computer */
   	socklen_t m_Addrlen; 
};

#endif /* __SERVER_H__ */