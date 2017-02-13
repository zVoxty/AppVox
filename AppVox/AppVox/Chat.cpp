#include "Chat.h"

Chat::Chat() {
	myChat.setupUi(this);
	chatPointer = this; // pointer which will trigger late the chat thread
	this->setWindowTitle("Chat");
}

Chat::~Chat() {
	CloseConnection(); // if chat dialog is closed then disconnect respective client
}

void Chat::AppendUser(const QString &userName) { // function used to append a user to connections list 
	QListWidgetItem *user = new QListWidgetItem(QIcon("user.png"), userName); // init the item which will pe appended
	myChat.connectionsList->addItem(user); // then append item to connections list
}

void Chat::AppendText(const QString &message)// function used to apped a message to chat
{
	QTextCursor cursor(myChat.mainChat->textCursor()); //cursor which will point to the bottom of chat
	cursor.movePosition(QTextCursor::End); // set cursor to bottom
	QTextTableFormat tableformat; 
	tableformat.setBorder(0); // set space between messages
	QTextTable *table = cursor.insertTable(1, 2, tableformat); // init a table which will contain the row where message will be appended
	table->cellAt(0, 1).firstCursorPosition().insertText(message); // append message in table which was been created above
	QScrollBar *bar = myChat.mainChat->verticalScrollBar(); // then scrol to down of chat box
	bar->setValue(bar->maximum()); // scroll to maxim on bottom
	myChat.inputText->clear(); // clear the inputText and wait for next message
	myChat.inputText->setFocus(); // focus the inputText box to send another message
}

void Chat::DisconnectClient(const int & clientIndex) { // function used to pop a connection from connectionList this is received from server
	QListWidgetItem *deleted; // init a item
	deleted = myChat.connectionsList->takeItem(clientIndex); // delete the item from connectins list triggered by it's index
	emit newMessage("Client " + deleted->text() + " disconnected"); // send message with item informations to chat
}

bool Chat::ProcessPacket(PacketType _packettype)
{
	try {
		switch (_packettype)
		{
			case PacketType::ChatMessage:{ // user to get a chat message from server
				std::string message; // init message
				if (!GetString(message)) // get message 
					throw QString("Cannot get message"); // if fails throw error
				emit newMessage(QString::fromStdString(message)); // else print the message in chat
				break;
			}
			case PacketType::newConnection: { // get from server a new connection
				std::string connectionName; // init connection name
				if(!GetString(connectionName)) // get connection name
					throw QString("Cannot get new connection"); // if fail throw error
				emit newUser(QString::fromStdString(connectionName)); // append to connections list the new connection
				emit newMessage(QString::fromStdString(connectionName) + " connected to chat."); // message on chat the new connection
				break;
			}
			case PacketType::UsersConnected: { // get from server a string which contain names of connections
				std::string connectionName; // init connection name
				if (!GetString(connectionName)) // get connection name
					throw QString("Cannot get new connection"); // if fail throw error
				QRegExp rx("(\\,)"); // init delimiter in our case is ',' 
				QStringList query = QString::fromStdString(connectionName).split(rx); //then split in a string list using above delimiter
				for (auto it : query) { // for every connection name
					emit newUser(it); // create new user in connectionslist widget
				}			
				break;
			}
			case PacketType::clientDisconnected: { // If receive client disconnected packet
				std::string connectionName; // init connection name
				if(!GetString(connectionName)) // get connection name
					throw QString("Cannot get new connection"); // if fail throw

				//loop throught connections 
				for (int row = 0; row < myChat.connectionsList->count(); row++){
					QListWidgetItem *item = myChat.connectionsList->item(row); 
					//fetch current item
					if (item->text() == QString::fromStdString(connectionName)) { // if item of connection list equal to connection name received
						emit userDisconnected(row); // disconnect it from connections
						break;
					}
				}
			}
			default:
				break;
		}
	}
	catch (QString message) {
		qDebug() << message;
	}
	return true;
}

bool Chat::setupUsername()
{
	setUsername *dialog = new setUsername;
	dialog->exec();
	clientName = dialog->usernamex;
	if (!clientName.isEmpty())
		return true;
	return false;
}

bool Chat::startConnection(){
	if (setupUsername()) {
		if (!Essentials::ConnectToServer("86.123.42.182", 1111)) //Call from inherited class "Essentials" the connect server function whick open the socket 
			return false;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ChatThread, NULL, NULL, NULL); //Create the client thread that will receive any data that the server sends.
		SendString(clientName.toStdString(), false);
		return true;
	}
	else {
		throw("Please set username.");
	}
}

void Chat::ChatThread()
{
	PacketType PacketType;

	while (true)
	{
		if (!chatPointer->GetPacketType(PacketType)) //Get packet type
			break; //If there is an issue getting the packet type, exit this loop

		if (!chatPointer->ProcessPacket(PacketType)) //Process packet (packet type)
			break; //If there is an issue processing the packet, exit this loop
	}

	qDebug("Lost connection to the server.");

	if (chatPointer->CloseConnection()) //Try to close socket connection..., If connection socket was closed properly
		qDebug("Socket to the server was closed successfuly.");
	else //If connection socket was not closed properly for some reason from our function
		qDebug("Socket was not able to be closed.");
}

void Chat::Submit() { // used to handle slot for Submit button 
	QString message = myChat.inputText->text(); // init message which contain the text from inputText 
	if(!message.isEmpty()) // if message is not empty
		SendString(message.toStdString()); // send message to server and then allconnections will receive the message
}