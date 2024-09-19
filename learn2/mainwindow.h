#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"  // Qt Designerで作成したUIヘッダー

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();  // ボタンのクリックイベントスロット

private:
    Ui::MainWindow *ui;  // UIオブジェクト
};

#endif // MAINWINDOW_H
