/********************************************************************************
** Form generated from reading UI file 'savewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEWINDOW_H
#define UI_SAVEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_Time;
    QLabel *label_DecknameMine;
    QLabel *label_DecknameEnemy;
    QLabel *label_Attackerside;
    QLabel *label_WinLose;
    QLabel *label_Reason;
    QRadioButton *radioButton_First;
    QRadioButton *radioButton_Second;
    QComboBox *comboBox_DecknameMine;
    QComboBox *comboBox_DecknameEnemy;
    QPushButton *saveButton;
    QLineEdit *nameInput;
    QRadioButton *radioButton_Win;
    QRadioButton *radioButton_Lose;
    QLineEdit *lineEdit_Reason;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_Time = new QLabel(centralwidget);
        label_Time->setObjectName("label_Time");
        label_Time->setGeometry(QRect(50, 30, 111, 51));
        QFont font;
        font.setPointSize(18);
        label_Time->setFont(font);
        label_Time->setStyleSheet(QString::fromUtf8("background-color: rgb(11, 15, 255);"));
        label_DecknameMine = new QLabel(centralwidget);
        label_DecknameMine->setObjectName("label_DecknameMine");
        label_DecknameMine->setGeometry(QRect(50, 110, 161, 51));
        label_DecknameMine->setFont(font);
        label_DecknameMine->setStyleSheet(QString::fromUtf8("background-color: rgb(11, 15, 255);"));
        label_DecknameMine->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_DecknameEnemy = new QLabel(centralwidget);
        label_DecknameEnemy->setObjectName("label_DecknameEnemy");
        label_DecknameEnemy->setGeometry(QRect(260, 110, 201, 51));
        label_DecknameEnemy->setFont(font);
        label_DecknameEnemy->setStyleSheet(QString::fromUtf8("background-color: rgb(11, 15, 255);"));
        label_DecknameEnemy->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_Attackerside = new QLabel(centralwidget);
        label_Attackerside->setObjectName("label_Attackerside");
        label_Attackerside->setGeometry(QRect(50, 310, 201, 51));
        label_Attackerside->setFont(font);
        label_Attackerside->setStyleSheet(QString::fromUtf8("background-color: rgb(11, 15, 255);"));
        label_Attackerside->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_WinLose = new QLabel(centralwidget);
        label_WinLose->setObjectName("label_WinLose");
        label_WinLose->setGeometry(QRect(270, 310, 161, 51));
        label_WinLose->setFont(font);
        label_WinLose->setStyleSheet(QString::fromUtf8("background-color: rgb(11, 15, 255);"));
        label_WinLose->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_Reason = new QLabel(centralwidget);
        label_Reason->setObjectName("label_Reason");
        label_Reason->setGeometry(QRect(460, 310, 161, 51));
        label_Reason->setFont(font);
        label_Reason->setStyleSheet(QString::fromUtf8("background-color: rgb(11, 15, 255);"));
        label_Reason->setAlignment(Qt::AlignmentFlag::AlignCenter);
        radioButton_First = new QRadioButton(centralwidget);
        radioButton_First->setObjectName("radioButton_First");
        radioButton_First->setGeometry(QRect(70, 380, 171, 41));
        QFont font1;
        font1.setPointSize(21);
        radioButton_First->setFont(font1);
        radioButton_Second = new QRadioButton(centralwidget);
        radioButton_Second->setObjectName("radioButton_Second");
        radioButton_Second->setGeometry(QRect(70, 420, 171, 41));
        radioButton_Second->setFont(font1);
        comboBox_DecknameMine = new QComboBox(centralwidget);
        comboBox_DecknameMine->setObjectName("comboBox_DecknameMine");
        comboBox_DecknameMine->setGeometry(QRect(50, 190, 161, 61));
        comboBox_DecknameEnemy = new QComboBox(centralwidget);
        comboBox_DecknameEnemy->setObjectName("comboBox_DecknameEnemy");
        comboBox_DecknameEnemy->setGeometry(QRect(260, 190, 161, 61));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(500, 180, 161, 61));
        nameInput = new QLineEdit(centralwidget);
        nameInput->setObjectName("nameInput");
        nameInput->setGeometry(QRect(500, 110, 261, 61));
        radioButton_Win = new QRadioButton(centralwidget);
        radioButton_Win->setObjectName("radioButton_Win");
        radioButton_Win->setGeometry(QRect(270, 380, 171, 41));
        radioButton_Win->setFont(font1);
        radioButton_Lose = new QRadioButton(centralwidget);
        radioButton_Lose->setObjectName("radioButton_Lose");
        radioButton_Lose->setGeometry(QRect(270, 420, 171, 41));
        radioButton_Lose->setFont(font1);
        lineEdit_Reason = new QLineEdit(centralwidget);
        lineEdit_Reason->setObjectName("lineEdit_Reason");
        lineEdit_Reason->setGeometry(QRect(460, 390, 261, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_Time->setText(QCoreApplication::translate("MainWindow", "date(now)", nullptr));
        label_DecknameMine->setText(QCoreApplication::translate("MainWindow", "my deck name", nullptr));
        label_DecknameEnemy->setText(QCoreApplication::translate("MainWindow", "enemy deck name", nullptr));
        label_Attackerside->setText(QCoreApplication::translate("MainWindow", "attacker side", nullptr));
        label_WinLose->setText(QCoreApplication::translate("MainWindow", "WIN / LOSE", nullptr));
        label_Reason->setText(QCoreApplication::translate("MainWindow", "REASON", nullptr));
        radioButton_First->setText(QCoreApplication::translate("MainWindow", "first", nullptr));
        radioButton_Second->setText(QCoreApplication::translate("MainWindow", "second", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save Button", nullptr));
        nameInput->setText(QCoreApplication::translate("MainWindow", "Input Deck Name", nullptr));
        radioButton_Win->setText(QCoreApplication::translate("MainWindow", "WIN", nullptr));
        radioButton_Lose->setText(QCoreApplication::translate("MainWindow", "LOSE", nullptr));
        lineEdit_Reason->setText(QCoreApplication::translate("MainWindow", "Input Win/Lose reason", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEWINDOW_H
