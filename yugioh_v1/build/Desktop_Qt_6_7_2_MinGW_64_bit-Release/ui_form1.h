/********************************************************************************
** Form generated from reading UI file 'form1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM1_H
#define UI_FORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form1
{
public:
    QPushButton *backmenuButton;
    QLineEdit *lineEdit;
    QPushButton *savedeckButton;
    QComboBox *yourdeckBox;
    QComboBox *enemydeckBox;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *firstsecondButton1;
    QRadioButton *firstsecondButton2;
    QPushButton *savedataButton;
    QLabel *label_4;
    QRadioButton *winloseButton1;
    QRadioButton *winloseButton2;
    QLabel *label_5;
    QTextEdit *reasontextEdit;
    QLabel *label_6;

    void setupUi(QWidget *Form1)
    {
        if (Form1->objectName().isEmpty())
            Form1->setObjectName("Form1");
        Form1->resize(800, 600);
        Form1->setSizeIncrement(QSize(0, 0));
        Form1->setBaseSize(QSize(1000, 600));
        backmenuButton = new QPushButton(Form1);
        backmenuButton->setObjectName("backmenuButton");
        backmenuButton->setGeometry(QRect(610, 490, 181, 91));
        lineEdit = new QLineEdit(Form1);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 480, 201, 71));
        savedeckButton = new QPushButton(Form1);
        savedeckButton->setObjectName("savedeckButton");
        savedeckButton->setGeometry(QRect(90, 550, 121, 41));
        yourdeckBox = new QComboBox(Form1);
        yourdeckBox->setObjectName("yourdeckBox");
        yourdeckBox->setGeometry(QRect(30, 70, 171, 111));
        enemydeckBox = new QComboBox(Form1);
        enemydeckBox->setObjectName("enemydeckBox");
        enemydeckBox->setGeometry(QRect(220, 70, 171, 111));
        label_1 = new QLabel(Form1);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(50, 30, 121, 31));
        label_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(Form1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 30, 121, 31));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(Form1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(470, 30, 121, 31));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        firstsecondButton1 = new QRadioButton(Form1);
        firstsecondButton1->setObjectName("firstsecondButton1");
        firstsecondButton1->setGeometry(QRect(470, 70, 111, 41));
        QFont font;
        font.setPointSize(21);
        firstsecondButton1->setFont(font);
        firstsecondButton2 = new QRadioButton(Form1);
        firstsecondButton2->setObjectName("firstsecondButton2");
        firstsecondButton2->setGeometry(QRect(470, 110, 121, 41));
        firstsecondButton2->setFont(font);
        savedataButton = new QPushButton(Form1);
        savedataButton->setObjectName("savedataButton");
        savedataButton->setGeometry(QRect(420, 490, 181, 91));
        label_4 = new QLabel(Form1);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 230, 121, 31));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        winloseButton1 = new QRadioButton(Form1);
        winloseButton1->setObjectName("winloseButton1");
        winloseButton1->setGeometry(QRect(30, 270, 111, 41));
        winloseButton1->setFont(font);
        winloseButton2 = new QRadioButton(Form1);
        winloseButton2->setObjectName("winloseButton2");
        winloseButton2->setGeometry(QRect(30, 310, 121, 41));
        winloseButton2->setFont(font);
        label_5 = new QLabel(Form1);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(220, 230, 171, 31));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        reasontextEdit = new QTextEdit(Form1);
        reasontextEdit->setObjectName("reasontextEdit");
        reasontextEdit->setGeometry(QRect(220, 280, 251, 71));
        label_6 = new QLabel(Form1);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 410, 181, 61));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(Form1);

        QMetaObject::connectSlotsByName(Form1);
    } // setupUi

    void retranslateUi(QWidget *Form1)
    {
        Form1->setWindowTitle(QCoreApplication::translate("Form1", "Form1", nullptr));
        backmenuButton->setText(QCoreApplication::translate("Form1", "Back to menu", nullptr));
        lineEdit->setText(QCoreApplication::translate("Form1", "Input deck name", nullptr));
        savedeckButton->setText(QCoreApplication::translate("Form1", "Save", nullptr));
        label_1->setText(QCoreApplication::translate("Form1", "Your deckname", nullptr));
        label_2->setText(QCoreApplication::translate("Form1", "Enemy deckname", nullptr));
        label_3->setText(QCoreApplication::translate("Form1", "Attacker Side", nullptr));
        firstsecondButton1->setText(QCoreApplication::translate("Form1", "First", nullptr));
        firstsecondButton2->setText(QCoreApplication::translate("Form1", "Second", nullptr));
        savedataButton->setText(QCoreApplication::translate("Form1", "Save", nullptr));
        label_4->setText(QCoreApplication::translate("Form1", "WIN or LOSE", nullptr));
        winloseButton1->setText(QCoreApplication::translate("Form1", "WIN", nullptr));
        winloseButton2->setText(QCoreApplication::translate("Form1", "LOSE", nullptr));
        label_5->setText(QCoreApplication::translate("Form1", "WIN or LOSE Reason", nullptr));
        label_6->setText(QCoreApplication::translate("Form1", "<html><head/><body><p>Input deck name<br/>(\343\202\202\343\201\227\343\203\207\343\203\203\343\202\255\345\220\215\343\201\214\350\246\213\343\201\244\343\201\213\343\202\211\343\201\252\343\201\221\343\202\214\343\201\260<br/>\343\201\223\343\201\223\343\201\213\343\202\211\350\277\275\345\212\240\343\201\247\343\201\215\343\201\276\343\201\231)</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form1: public Ui_Form1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM1_H
