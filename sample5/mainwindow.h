#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openSecondWindow();  // SecondWindowを開くスロット

private:
    Ui::MainWindow *ui;
    SecondWindow *secondWindow;  // SecondWindowを保持するメンバ変数
};

#endif // MAINWINDOW_H
