#ifndef APPVOX_H
#define APPVOX_H

#include "Essentials.h"
#include "Chat.h"

class AppVox : public QMainWindow, public Essentials
{
	Q_OBJECT
public: //Public functions
	AppVox(QWidget *parent = 0);
	~AppVox();

private: //Private variable
	Ui::AppVoxClass ui;

private slots:
	void EnableChat();
};

#endif // APPVOX_H
