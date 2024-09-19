#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);  // UIのセットアップ
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);  // ボタンクリックイベントの接続
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // ボタンクリック時の処理
    ui->pushButton->setText("Clicked!");
}
