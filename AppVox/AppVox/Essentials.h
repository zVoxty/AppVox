#ifndef ESSENTIALS_H
#define ESSENTIALS_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib") //Required for WinSock
#include <QtWidgets/QMainWindow>
#include <string>
#include <WinSock2.h>
#include <Windows.h>
#include <QFile>
#include <qtextstream.h>
#include <QTextTable>
#include <QScrollBar>
#include <QString>
#include <QDebug>

//Other
#include "ui_Chat.h"
#include "ui_AppVox.h"
#include "PacketType.h"

class Essentials {
public:
	Essentials();
	~Essentials();

	bool ConnectToServer(std::string IP, int PORT); //Stabilish a socket connection to server
	bool CloseConnection();	//Close a connection

	virtual bool ProcessPacket(PacketType _packettype);

	//Get Functions
	bool GetInt32_t(int32_t & _int32_t);
	bool recvall(char * data, int totalbytes);
	bool GetPacketType(PacketType & _packettype);
	bool GetString(std::string & _string);

	//Sending Funcs
	bool sendall(char * data, int totalbytes);
	bool SendInt32_t(int32_t _int32_t);
	bool SendPacketType(PacketType _packettype);
	bool SendString(std::string & _string, bool IncludePacketType = true);

	SOCKET Connection;
	SOCKADDR_IN addr;
	int sizeOfAddr = sizeof(addr);

	bool isConnected;
};

#endif // !ESSENTIALS_H
