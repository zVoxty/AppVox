#include "Server.h"

bool Server::ProcessPacket(int ID, PacketType _packettype)
{
	switch (_packettype)
	{
		case PacketType::ChatMessage: //Packet Type: chat message
		{
			std::string message; //string to store our message we received
			if (!GetString(ID, message)) //Get the chat message and store it in variable: Message
				return false; //If we do not properly get the chat message, return false

							  //Next we need to send the message out to each user
			for (size_t i = 0; i < connections.size(); i++)
			{
				if (connections[i]->ActiveConnection == false) //if connection is not active
					continue; //Skip logic for this connection
				if (i == ID) { //If connection is the user who sent the message...
					SendString(i, "You: " + message); //send message to connection i
				}
				else {
					SendString(i, connections[i]->connectionName + message); //send message to connection i
				}			
			}

			std::cout << "Processed chat message packet from user " << connections[ID]->connectionName << " message is " << message << std::endl;
			break;
		}
		case PacketType::FileTransferRequestFile:
		{
			std::string FileName; //string to store file name
			if (!GetString(ID, FileName)) //If issue getting file name
				return false; //Failure to process packet

			connections[ID]->file.infileStream.open(FileName, std::ios::binary | std::ios::ate); //Open file to read in binary | ate mode. We use ate so we can use tellg to get file size. We use binary because we need to read bytes as raw data
			if (!connections[ID]->file.infileStream.is_open()) //If file is not open? (Error opening file?)
			{
				std::cout << "Client: " << ID << " requested file: " << FileName << ", but that file does not exist." << std::endl;
				std::string ErrMsg = "\nRequested file: " + FileName + " does not exist or was not found.";
				SendString(ID, ErrMsg); //Send error msg string to client
				return true;
			}

			connections[ID]->file.fileName = FileName; //set file name just so we can print it out after done transferring
			connections[ID]->file.fileSize = connections[ID]->file.infileStream.tellg(); //Get file size
			connections[ID]->file.infileStream.seekg(0); //Set cursor position in file back to offset 0 for when we read file
			connections[ID]->file.fileOffset = 0; //Update file offset for knowing when we hit end of file

			if (!HandleSendFile(ID)) //Attempt to send byte buffer from file. If failure...
				return false;

			break;
		}
		case PacketType::FileTransferRequestNextBuffer:
		{
			if (!HandleSendFile(ID)) //Attempt to send byte buffer from file. If failure...
				return false;
			break;
		}

		default: //If packet type is not accounted for
		{
			std::cout << "Unrecognized packet: " << (int32_t)_packettype << std::endl; //Display that packet was not found
			break;
		}
	}
	return true;
}