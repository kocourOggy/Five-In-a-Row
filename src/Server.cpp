 //*****************************************************************

#include "Server.h"

//*****************************************************************


Server::Server()
{
  m_Port = 0;
}

void Server::setServer(const std::string & port)
{
  m_Port = atoi( port.c_str() );
  if ((m_MainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
  {
    throw "Unable to set the server socket";
  }

  m_SockName.sin_family = AF_INET;
  m_SockName.sin_port = htons(m_Port);
  m_SockName.sin_addr.s_addr = INADDR_ANY;

  if (bind(m_MainSocket, (sockaddr *)&m_SockName, sizeof(m_SockName)) == -1)
  {
    throw "Unable to set the server socket";
  }

  if (listen(m_MainSocket, 10) == -1)
  {
    throw "Unable to set a server queue";
    //return -1;
  }
}

void Server::closeConnection()
{
  if (m_Port != 0)
  {
    close(m_Client);
    close(m_MainSocket);
  }
  m_Port = 0;
}

Server::~Server() 
{
  if (m_Port != 0) close(m_MainSocket);
}


void Server::ReadytoConnect()
{

	m_Addrlen = sizeof(m_ClientInfo);
	// block program until it receive connection from client
	m_Client = accept(m_MainSocket, (sockaddr*)&m_ClientInfo, &m_Addrlen);
  if (m_Client == -1)
  {
   	throw "Server cannot connect to a client";
  }
}



void Server::sendCoor(const Coordinate & coordinate)
{
	m_BuffCoor[0] = coordinate.m_Row;
	m_BuffCoor[1] = coordinate.m_Column;
	if ( send( m_Client, m_BuffCoor, sizeof(m_BuffCoor), 0 ) == -1 )
    throw "Server cannot send data";
}

Coordinate Server::listenCoor()
{

  std::clock_t startTime = std::clock();
  double timeInSeconds = 0;
	m_SizeData = 0;
	while ( 1 )
	{
    std::clock_t endTime = std::clock();
		m_SizeData = recv( m_Client, m_BuffCoor, sizeof(m_BuffCoor), 0 );
    if ( m_SizeData == 8 ) break;

    timeInSeconds = (endTime - startTime) / (double) CLOCKS_PER_SEC;
    
    if ( timeInSeconds > WAITTIME )
    {
      
      throw ("Exceeded limit time for connection " +
                    std::to_string(WAITTIME)).c_str();
      break;
	   }
  }
	return Coordinate( m_BuffCoor[0], m_BuffCoor[1] );
}