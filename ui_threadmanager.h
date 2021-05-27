/********************************************************************************
** Form generated from reading UI file 'threadmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREADMANAGER_H
#define UI_THREADMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThreadManager
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_Close;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ThreadManager)
    {
        if (ThreadManager->objectName().isEmpty())
            ThreadManager->setObjectName(QString::fromUtf8("ThreadManager"));
        ThreadManager->resize(925, 300);
        centralWidget = new QWidget(ThreadManager);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_Close = new QPushButton(centralWidget);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        pushButton_Close->setGeometry(QRect(820, 220, 75, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(640, 220, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(730, 220, 75, 23));
        ThreadManager->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ThreadManager);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 21));
        ThreadManager->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ThreadManager);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ThreadManager->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ThreadManager);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ThreadManager->setStatusBar(statusBar);

        retranslateUi(ThreadManager);

        QMetaObject::connectSlotsByName(ThreadManager);
    } // setupUi

    void retranslateUi(QMainWindow *ThreadManager)
    {
        ThreadManager->setWindowTitle(QApplication::translate("ThreadManager", "ThreadManager", nullptr));
        pushButton_Close->setText(QApplication::translate("ThreadManager", "Close", nullptr));
        pushButton->setText(QApplication::translate("ThreadManager", "Stop", nullptr));
        pushButton_2->setText(QApplication::translate("ThreadManager", "Check", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThreadManager: public Ui_ThreadManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREADMANAGER_H
