#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::someFunction()
{
    // 例えば、ボタンのクリックに関する設定をする
    connect(ui->someButton, &QPushButton::clicked, this, &SecondWindow::someSlotFunction);
}
