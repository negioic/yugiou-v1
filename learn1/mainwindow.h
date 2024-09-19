#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void onButtonClicked();
    void openSecondWindow();

private:
    QPushButton *button;
    QLabel *label;
};

#endif // MAINWINDOW_H
