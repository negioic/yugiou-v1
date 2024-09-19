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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form1
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *saveButton;
    QComboBox *comboBox1;
    QComboBox *comboBox2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QWidget *Form1)
    {
        if (Form1->objectName().isEmpty())
            Form1->setObjectName("Form1");
        Form1->resize(800, 600);
        Form1->setSizeIncrement(QSize(0, 0));
        Form1->setBaseSize(QSize(1000, 600));
        pushButton = new QPushButton(Form1);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(580, 490, 181, 91));
        lineEdit = new QLineEdit(Form1);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(40, 460, 201, 71));
        saveButton = new QPushButton(Form1);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(100, 530, 141, 61));
        comboBox1 = new QComboBox(Form1);
        comboBox1->setObjectName("comboBox1");
        comboBox1->setGeometry(QRect(30, 70, 171, 111));
        comboBox2 = new QComboBox(Form1);
        comboBox2->setObjectName("comboBox2");
        comboBox2->setGeometry(QRect(220, 70, 171, 111));
        label = new QLabel(Form1);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 30, 121, 31));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
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
        radioButton = new QRadioButton(Form1);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(470, 70, 111, 41));
        QFont font;
        font.setPointSize(21);
        radioButton->setFont(font);
        radioButton_2 = new QRadioButton(Form1);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(470, 110, 121, 41));
        radioButton_2->setFont(font);

        retranslateUi(Form1);

        QMetaObject::connectSlotsByName(Form1);
    } // setupUi

    void retranslateUi(QWidget *Form1)
    {
        Form1->setWindowTitle(QCoreApplication::translate("Form1", "Form1", nullptr));
        pushButton->setText(QCoreApplication::translate("Form1", "Back to menu", nullptr));
        lineEdit->setText(QCoreApplication::translate("Form1", "Input deck name", nullptr));
        saveButton->setText(QCoreApplication::translate("Form1", "Save", nullptr));
        label->setText(QCoreApplication::translate("Form1", "Your deckname", nullptr));
        label_2->setText(QCoreApplication::translate("Form1", "Enemy deckname", nullptr));
        label_3->setText(QCoreApplication::translate("Form1", "Attacker Side", nullptr));
        radioButton->setText(QCoreApplication::translate("Form1", "First", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Form1", "Second", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form1: public Ui_Form1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM1_H
