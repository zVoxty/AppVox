#include "Chat.h"

Chat::Chat() {
	myChat.setupUi(this);

	connect(myChat.submitText, SIGNAL(clicked()), this, SLOT(Submit()));

	myChat.textEdit->setReadOnly(true);

	QListWidgetItem *item = new QListWidgetItem(QIcon("user.png"), "Test");
	myChat.listWidget->addItem(item);

	if (!ConnectToServer("86.126.33.49", 1111)) {
		MessageBoxA(NULL, "Error connection to server", "Error", MB_OK | MB_ICONERROR);
		return;
	}
}

Chat::~Chat() {
	
}

void Chat::AppendText(QString from, QString message)
{
	QTextCursor cursor(myChat.textEdit->textCursor());
	cursor.movePosition(QTextCursor::End);
	QTextTableFormat tableformat;
	tableformat.setBorder(0);
	QTextTable *table = cursor.insertTable(1, 2, tableformat);
	table->cellAt(0, 0).firstCursorPosition().insertText(from + " :");
	table->cellAt(0, 1).firstCursorPosition().insertText(message);
	QScrollBar *bar = myChat.textEdit->verticalScrollBar();
	bar->setValue(bar->maximum());
	myChat.inputText->setFocus();
}

void Chat::Submit() {
	QString message = myChat.inputText->text();
	SendString(message.toStdString());
	myChat.inputText->clear();
}