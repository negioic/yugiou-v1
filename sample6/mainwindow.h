#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"  // SecondWindowをインクルード

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openSecondWindowButton_clicked();  // ボタンがクリックされたときのスロット

private:
    Ui::MainWindow *ui;
    SecondWindow *secondWindow;  // SecondWindowへのポインタ
};

#endif // MAINWINDOW_H
