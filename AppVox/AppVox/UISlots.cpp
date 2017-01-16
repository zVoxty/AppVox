#include "AppVox.h"

void AppVox::exit() {
	QApplication::exit();
}

void AppVox::ConnectBtn() {
	
	ui.connectToServer->setDisabled(true);
	ui.disconnectToServer->setDisabled(false);
	
}

void AppVox::DisconnectBtn()
{
	if (!CloseConnection()) {
		qDebug("Problem disconnection !");
		return;
	}
	ui.connectToServer->setDisabled(false);
	ui.disconnectToServer->setDisabled(true);
}

void AppVox::EnableChat() {
	Chat chatDialog;
	chatDialog.exec();
}