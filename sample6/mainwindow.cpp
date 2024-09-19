#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , secondWindow(new SecondWindow())  // SecondWindowを初期化
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_openSecondWindowButton_clicked);  // ボタンのクリックを接続
}

MainWindow::~MainWindow()
{
    delete ui;
    delete secondWindow;  // メモリを解放
}

void MainWindow::on_openSecondWindowButton_clicked()
{
    secondWindow->show();  // SecondWindowを表示
    this->close();         // MainWindowを閉じる
}
