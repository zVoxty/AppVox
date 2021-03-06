/********************************************************************************
** Form generated from reading UI file 'Chat.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *mainChat;
    QListWidget *connectionsList;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputText;
    QPushButton *submitText;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QStringLiteral("Chat"));
        Chat->setWindowModality(Qt::NonModal);
        Chat->setEnabled(true);
        Chat->resize(385, 300);
        Chat->setMinimumSize(QSize(385, 300));
        Chat->setMaximumSize(QSize(385, 300));
        QIcon icon;
        icon.addFile(QStringLiteral(":/AppVox/appicon.png"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QStringLiteral(":/AppVox/appicon.png"), QSize(), QIcon::Disabled, QIcon::On);
        Chat->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Chat);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mainChat = new QTextEdit(Chat);
        mainChat->setObjectName(QStringLiteral("mainChat"));
        mainChat->setMaximumSize(QSize(230, 248));
        mainChat->setSizeIncrement(QSize(0, 0));
        mainChat->setBaseSize(QSize(0, 0));
        mainChat->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        mainChat->setReadOnly(true);

        horizontalLayout_2->addWidget(mainChat);

        connectionsList = new QListWidget(Chat);
        connectionsList->setObjectName(QStringLiteral("connectionsList"));
        connectionsList->setMaximumSize(QSize(120, 248));

        horizontalLayout_2->addWidget(connectionsList);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        inputText = new QLineEdit(Chat);
        inputText->setObjectName(QStringLiteral("inputText"));

        horizontalLayout->addWidget(inputText);

        submitText = new QPushButton(Chat);
        submitText->setObjectName(QStringLiteral("submitText"));

        horizontalLayout->addWidget(submitText);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(submitText, inputText);
        QWidget::setTabOrder(inputText, connectionsList);
        QWidget::setTabOrder(connectionsList, mainChat);

        retranslateUi(Chat);
        QObject::connect(submitText, SIGNAL(clicked()), Chat, SLOT(Submit()));
        QObject::connect(Chat, SIGNAL(newMessage(QString)), Chat, SLOT(AppendText(QString)));
        QObject::connect(Chat, SIGNAL(newUser(QString)), Chat, SLOT(AppendUser(QString)));
        QObject::connect(Chat, SIGNAL(userDisconnected(int)), Chat, SLOT(DisconnectClient(int)));

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QDialog *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Dialog", Q_NULLPTR));
        submitText->setText(QApplication::translate("Chat", "Submit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
