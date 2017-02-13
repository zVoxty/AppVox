#include "AppVox.h"

void AppVox::EnableChat() {
	Chat chatDialog;
	try {
		if (chatDialog.startConnection())
			chatDialog.exec();
		else
			throw("Cannot connect");
	}
	catch (const char * message) {
		QMessageBox::information(this, "Info", message);
	}
}