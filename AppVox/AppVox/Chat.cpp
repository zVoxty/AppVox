#include "Chat.h"

Chat::Chat() {
	myChat.setupUi(this);

	myChat.textEdit->setReadOnly(true);

	QListWidgetItem *item = new QListWidgetItem(QIcon("user.png"), "Test");
	myChat.listWidget->addItem(item);

	if (!ConnectToServer("86.126.33.49", 1111))
		MessageBoxA(NULL, "Cannot connect", "Error", MB_OK);

	chatPointer = this;

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ChatThread, NULL, NULL, NULL); //Create the client thread that will receive any data that the server sends.

}

Chat::~Chat() {
	CloseConnection();
}

void Chat::AppendText(const QString &message)
{
	QTextCursor cursor(myChat.textEdit->textCursor());
	cursor.movePosition(QTextCursor::End);
	QTextTableFormat tableformat;
	tableformat.setBorder(0);
	QTextTable *table = cursor.insertTable(1, 2, tableformat);
	table->cellAt(0, 0).firstCursorPosition().insertText("Server: ");
	table->cellAt(0, 1).firstCursorPosition().insertText(message);
	QScrollBar *bar = myChat.textEdit->verticalScrollBar();
	bar->setValue(bar->maximum());
	myChat.inputText->clear();
	myChat.inputText->setFocus();
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
			QString qMessage = QString::fromStdString(message);
			emit newMessage(qMessage);
			break;
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