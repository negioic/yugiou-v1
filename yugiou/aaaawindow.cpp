#include "aaaawindow.h"
#include "ui_aaaawindow.h"

aaaaWindow::aaaaWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::aaaaWindow)
{
    ui->setupUi(this);
}

aaaaWindow::~aaaaWindow()
{
    delete ui;
}
