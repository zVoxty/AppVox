#ifndef CHAT_H
#define CHAT_H

#include "Essentials.h"

class Chat : public QDialog, public Essentials{
	Q_OBJECT
public:
	Chat();
	~Chat();

public: // Private functions
	
private: // Private variables
	Ui::Chat myChat;

	static void ChatThread(); // This function handle packets from server

	bool ProcessPacket(PacketType _packettype);
	
signals:
	void newMessage(const QString &from);

	
private slots:
	void Submit();
	void AppendText(const QString &message);
	
};

static Chat * chatPointer; //This chatPointer is necessary so that the ClientThread method can access the Client instance/methods. Since the ClientThread method is static, this is the simplest workaround I could think of since there will only be one instance of the client.

#endif // !CHAT_H
