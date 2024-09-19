#include "mainwindow.h"  // MainWindow クラスのヘッダーをインクルード
#include "savewindow.h" // 次のウィンドウ用のヘッダー
#include "./ui_mainwindow.h" // UI デザインを読み込むためのヘッダー

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ボタンをクリックすると次のウィンドウが開く
    connect(ui->menuButton, &QPushButton::clicked, this, &MainWindow::openSaveWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSaveWindow()
{
    // 次の画面（ウィンドウ）を表示する
    saveWindow = new SaveWindow(this); // 次のウィンドウを作成
    saveWindow->show();                  // 新しいウィンドウを表示
    this->hide();                          // 現在のメニュー画面を隠す（オプション）
}
