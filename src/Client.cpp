 //*****************************************************************

#include "Client.h"

//******************************************************************

Client::Client()
{
	m_Port = 0;
}

void Client::setClient()
{
	m_MySocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_MySocket == -1) throw "Unable to set a client socket";
}


Client::~Client()
{
	if (m_Port != 0) close(m_MySocket);
}

void Client::connectToServer(const std::string & host, const std::string & port)
{
	
	m_Port = atoi( port.c_str() );
	m_Host = gethostbyname( host.c_str() );

	m_ServerSock.sin_family = AF_INET;
	m_ServerSock.sin_port = htons(m_Port);
	memcpy(&(m_ServerSock.sin_addr), m_Host->h_addr, m_Host->h_length);


	std::clock_t startTime = std::clock();
	double timeInSeconds = 0;
	while (timeInSeconds < WAITTIME)
	{
    	if (connect(m_MySocket, (sockaddr *)&m_ServerSock, sizeof(m_ServerSock)) == 0)
    	{
        	return;
    	}
    	std::clock_t endTime = std::clock();

    	timeInSeconds = (endTime - startTime) / (double) CLOCKS_PER_SEC;
	}

	throw ("Exceeded limit time for connection " + std::to_string(timeInSeconds)).c_str();
}


void Client::sendCoor(const Coordinate & coordinate)
{
	m_BuffCoor[0] = coordinate.m_Row;
	m_BuffCoor[1] = coordinate.m_Column;
	if ( send( m_MySocket, m_BuffCoor, sizeof(m_BuffCoor), 0 ) == -1 )
		throw "Client cannot send data";

	/*std::cout << "Klient odeslal	" << coordinate << std::endl;*/
}


Coordinate Client::listenCoor()
{
	
	std::clock_t startTime = std::clock();
	double timeInSeconds = 0;
	m_SizeData = 0;
	while ( 1 )
	{
		m_SizeData = recv( m_MySocket, m_BuffCoor, sizeof(m_BuffCoor), 0 );
		if ( m_SizeData == 8 ) break;
		
		std::clock_t endTime = std::clock();
		timeInSeconds = (endTime - startTime) / (double) CLOCKS_PER_SEC;
		if ( timeInSeconds > WAITTIME )
		{
			
			throw ("Exceeded limit time for connection " +
										std::to_string(WAITTIME)).c_str();
			break;
		}
	}

	/*std::cout << "Klient prijal	" << m_BuffCoor[0] << ", " << m_BuffCoor[1] << std::endl;*/
	return Coordinate( m_BuffCoor[0], m_BuffCoor[1] );
}

void Client::closeConnection()
{
	if (m_Port != 0)
	{
		close(m_MySocket);
		m_Port = 0;
	}
}