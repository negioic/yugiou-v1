/********************************************************************************
** Form generated from reading UI file 'form2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM2_H
#define UI_FORM2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form2
{
public:
    QPushButton *backmenuButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Form2)
    {
        if (Form2->objectName().isEmpty())
            Form2->setObjectName("Form2");
        Form2->resize(704, 407);
        backmenuButton = new QPushButton(Form2);
        backmenuButton->setObjectName("backmenuButton");
        backmenuButton->setGeometry(QRect(590, 340, 101, 51));
        tableWidget = new QTableWidget(Form2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 40, 671, 281));

        retranslateUi(Form2);

        QMetaObject::connectSlotsByName(Form2);
    } // setupUi

    void retranslateUi(QWidget *Form2)
    {
        Form2->setWindowTitle(QCoreApplication::translate("Form2", "Form", nullptr));
        backmenuButton->setText(QCoreApplication::translate("Form2", "Back to Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form2: public Ui_Form2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM2_H
