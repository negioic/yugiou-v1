#include "mainwindow.h"
#include "secondwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    // ウィンドウのサイズを設定 (幅: 800, 高さ: 600)
    this->resize(800, 600);

    // ボタンを作成
    button = new QPushButton("Open Second Window", this);
    button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));

    // ラベルを作成
    label = new QLabel(this);
    label->setGeometry(QRect(QPoint(100, 200), QSize(200, 50)));
    label->setText("Main Window");

    // ボタンクリック時の動作を設定
    connect(button, &QPushButton::clicked, this, &MainWindow::openSecondWindow);
}

MainWindow::~MainWindow() {
}

void MainWindow::openSecondWindow() {
    // 新しいウィンドウを作成し、表示
    SecondWindow *secondWindow = new SecondWindow(this);
    secondWindow->show(); // モーダレスダイアログとして表示
}
