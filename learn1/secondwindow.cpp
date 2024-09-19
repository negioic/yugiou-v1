#include "secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) : QDialog(parent)
{
    // ウィンドウのタイトルとサイズを設定
    this->setWindowTitle("Second Window");
    this->resize(400, 300);
}

SecondWindow::~SecondWindow()
{
}
