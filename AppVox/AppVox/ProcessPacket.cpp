#include "Essentials.h"

bool Essentials::ProcessPacket(PacketType _packettype)
{	
	try {
		switch (_packettype)
		{
			case PacketType::ChatMessage: {

				std::string message;
				if (!GetString(message))
					throw("Cannot get message");
				QString qMessage = QString::fromStdString(message);
				qDebug() << qMessage;
				break;
			}

		default: //If packet type is not accounted for
			std::string defaultCase = "Unrecognized packet: " + std::to_string((int32_t)_packettype) + "\0";
			throw(defaultCase);
			break;
		}
	}
	catch (const char * msg) {
		MessageBoxA(NULL, msg, "Error", MB_OK | MB_ICONERROR);
		return false;
	}
	return true;
}