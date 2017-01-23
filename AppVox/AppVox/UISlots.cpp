#include "AppVox.h"

void AppVox::EnableChat() {
	Chat chatDialog;
	if(chatDialog.startConnection())
		chatDialog.exec();
	else
		MessageBoxA(NULL, "Cannot connect", "Error", MB_OK);
}