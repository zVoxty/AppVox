#include "Essentials.h"

Essentials::Essentials()
{
}

Essentials::~Essentials()
{
}

bool Essentials::ConnectToServer(std::string IP, int PORT)
{
	//Winsock Startup
	WSAData wsaData;

	WORD DllVersion = MAKEWORD(2, 1);

	if (WSAStartup(DllVersion, &wsaData) != 0)
		qDebug("Winsock startup failed");

	addr.sin_addr.s_addr = inet_addr(IP.c_str()); //Address 127.0.0.1 = localhost (This pc)

	addr.sin_port = htons(PORT); //Port to connect on

	addr.sin_family = AF_INET; //IPv4 Socket

	Connection = socket(AF_INET, SOCK_STREAM, NULL); //Set Connection socket

	if (connect(Connection, (SOCKADDR*)&addr, sizeOfAddr) != 0) {
		qDebug("Problem Connection to server");
		return false;
	}

	isConnected = true;
	return true;
}


bool Essentials::CloseConnection()
{
	if (closesocket(Connection) == SOCKET_ERROR)
	{
		if (WSAGetLastError() == WSAENOTSOCK) //If socket error is that operation is not performed on a socket (This happens when the socket has already been closed)
			return true; //return true since connection has already been closed
		qDebug("Failed to close the socket. Winsock Error.");
		return false;
	}
	isConnected = false;
	return true;
}