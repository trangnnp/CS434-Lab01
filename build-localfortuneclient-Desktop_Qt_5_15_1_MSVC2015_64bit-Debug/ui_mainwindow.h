/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *screen1;
    QGridLayout *listroom;
    QLabel *label;
    QListWidget *listWidget;
    QGridLayout *hello;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(944, 304);
        QFont font;
        font.setFamily(QString::fromUtf8("Tahoma"));
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tahoma"));
        font1.setPointSize(16);
        centralwidget->setFont(font1);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        screen1 = new QGridLayout();
        screen1->setObjectName(QString::fromUtf8("screen1"));
        screen1->setHorizontalSpacing(40);
        screen1->setContentsMargins(-1, -1, 0, -1);
        listroom = new QGridLayout();
        listroom->setObjectName(QString::fromUtf8("listroom"));
        listroom->setHorizontalSpacing(0);
        listroom->setVerticalSpacing(10);
        listroom->setContentsMargins(-1, -1, 40, -1);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        listroom->addWidget(label, 0, 0, 1, 1);

        listWidget = new QListWidget(centralwidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Tahoma"));
        font2.setPointSize(14);
        listWidget->setFont(font2);

        listroom->addWidget(listWidget, 1, 0, 1, 1);


        screen1->addLayout(listroom, 0, 1, 1, 1);

        hello = new QGridLayout();
        hello->setObjectName(QString::fromUtf8("hello"));
        hello->setVerticalSpacing(20);
        hello->setContentsMargins(40, -1, 40, 0);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(70, 30));
        pushButton->setFont(font1);

        hello->addWidget(pushButton, 4, 0, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setBaseSize(QSize(0, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Tahoma"));
        font3.setPointSize(90);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        hello->addWidget(label_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(280, 25));
        lineEdit->setMaximumSize(QSize(91, 16777215));
        lineEdit->setBaseSize(QSize(0, 0));
        lineEdit->setFont(font1);

        hello->addWidget(lineEdit, 2, 0, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);


        screen1->addLayout(hello, 0, 0, 1, 1);

        screen1->setColumnStretch(0, 3);

        horizontalLayout->addLayout(screen1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 944, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "List room", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "room 1", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "room 2", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "room 3", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "room 4", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "room 5", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QCoreApplication::translate("MainWindow", "Continue", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Welcome to Cat Millionaire!", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
