#include "Chat.h"

Chat::Chat() {
	myChat.setupUi(this);
	chatPointer = this;
}

Chat::~Chat() {
	CloseConnection();
}

void Chat::AppendUser(const QString &userName) {
	QListWidgetItem *user = new QListWidgetItem(QIcon("user.png"), userName);
	myChat.connectionsList->addItem(user);
}

void Chat::AppendText(const QString &message)
{
	QTextCursor cursor(myChat.mainChat->textCursor());
	cursor.movePosition(QTextCursor::End);
	QTextTableFormat tableformat;
	tableformat.setBorder(0);
	QTextTable *table = cursor.insertTable(1, 2, tableformat);
	table->cellAt(0, 1).firstCursorPosition().insertText(message);
	QScrollBar *bar = myChat.mainChat->verticalScrollBar();
	bar->setValue(bar->maximum());
	myChat.inputText->clear();
	myChat.inputText->setFocus();
}

void Chat::DisconnectClient(const int & clientIndex) {
	QListWidgetItem *deleted;
	deleted = myChat.connectionsList->takeItem(clientIndex);
	emit newMessage("Client " + deleted->text() + " disconnected");
}

bool Chat::ProcessPacket(PacketType _packettype)
{
	try {
		switch (_packettype)
		{
			case PacketType::ChatMessage:{
				std::string message;
				if (!GetString(message))
					throw QString("Cannot get message");
				emit newMessage(QString::fromStdString(message));
				break;
			}
			case PacketType::newConnection: {
				std::string connectionName;
				if(!GetString(connectionName))
					throw QString("Cannot get new connection");
				emit newUser(QString::fromStdString(connectionName));
				emit newMessage(QString::fromStdString(connectionName) + " connected to chat.");
				break;
			}
			case PacketType::UsersConnected: {
				std::string connectionName;
				if (!GetString(connectionName))
					throw QString("Cannot get new connection");
				QRegExp rx("(\\,)");
				QStringList query = QString::fromStdString(connectionName).split(rx);
				for (auto it : query) {
					emit newUser(it);
				}			
				break;
			}
			case PacketType::clientDisconnected: {
				std::string connectionName;
				if(!GetString(connectionName))
					throw QString("Cannot get new connection");
				for (int row = 0; row < myChat.connectionsList->count(); row++){
					QListWidgetItem *item = myChat.connectionsList->item(row);
					if (item->text() == QString::fromStdString(connectionName)) {
						emit userDisconnected(row);
						break;
					}
				}
				
				//emit newMessage(QString::fromStdString(connectionName) + " disconnected from chat.");
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

bool Chat::startConnection(){
	if (!Essentials::ConnectToServer("86.126.33.49", 1111))
		return false;

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ChatThread, NULL, NULL, NULL); //Create the client thread that will receive any data that the server sends.

	return true;
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

void Chat::Submit() {
	QString message = myChat.inputText->text();
	if(!message.isEmpty())
		SendString(message.toStdString());
}