#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ボタンがクリックされたらSecondWindowを表示
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::openSecondWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSecondWindow() {
    secondWindow = new SecondWindow(this);
    secondWindow->show();
    this->hide();  // MainWindowを非表示にする場合
}
