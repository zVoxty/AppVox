/********************************************************************************
** Form generated from reading UI file 'AppVox.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPVOX_H
#define UI_APPVOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppVoxClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *chatButton;
    QPushButton *exit;

    void setupUi(QMainWindow *AppVoxClass)
    {
        if (AppVoxClass->objectName().isEmpty())
            AppVoxClass->setObjectName(QStringLiteral("AppVoxClass"));
        AppVoxClass->resize(576, 402);
        AppVoxClass->setStyleSheet(QStringLiteral("background-image: url(:/AppVox/imgg.jpg);"));
        centralWidget = new QWidget(AppVoxClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(190, 380, 191, 16));
        label->setStyleSheet(QLatin1String("color:white;\n"
"background:none;"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(220, 170, 119, 66));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        chatButton = new QPushButton(widget);
        chatButton->setObjectName(QStringLiteral("chatButton"));
        chatButton->setMinimumSize(QSize(117, 0));
        chatButton->setStyleSheet(QLatin1String("background:none;\n"
"font: 12pt \"MV Boli\";"));

        verticalLayout->addWidget(chatButton);

        exit = new QPushButton(widget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setMinimumSize(QSize(117, 0));
        exit->setStyleSheet(QLatin1String("\n"
"font: 12pt \"MV Boli\";"));

        verticalLayout->addWidget(exit);

        AppVoxClass->setCentralWidget(centralWidget);

        retranslateUi(AppVoxClass);
        QObject::connect(exit, SIGNAL(clicked()), AppVoxClass, SLOT(close()));
        QObject::connect(chatButton, SIGNAL(clicked()), AppVoxClass, SLOT(EnableChat()));

        QMetaObject::connectSlotsByName(AppVoxClass);
    } // setupUi

    void retranslateUi(QMainWindow *AppVoxClass)
    {
        AppVoxClass->setWindowTitle(QApplication::translate("AppVoxClass", "AppVox", Q_NULLPTR));
        label->setText(QApplication::translate("AppVoxClass", "zVoxty Corporation All Rights Reserved", Q_NULLPTR));
        widget->setStyleSheet(QApplication::translate("AppVoxClass", "background:none;\n"
"font: 12pt \"MV Boli\";", Q_NULLPTR));
        chatButton->setText(QApplication::translate("AppVoxClass", "Chat", Q_NULLPTR));
        exit->setText(QApplication::translate("AppVoxClass", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AppVoxClass: public Ui_AppVoxClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPVOX_H
