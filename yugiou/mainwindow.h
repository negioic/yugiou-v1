#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void opensavewindow(); // ここに関数のプロトタイプを宣言

private:
    Ui::MainWindow *ui;
    SaveWindow *saveWindow; // 次のウィンドウを開くためのポインタ
};

#endif // MAINWINDOW_H
