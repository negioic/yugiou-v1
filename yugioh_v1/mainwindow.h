#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "ui_mainwindow.h"
#include "ui_form1.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void GoToScreen0();
    void GoToScreen1();
    void onSaveButtonClicked();  // 名前を保存するボタンのクリック時の処理
    void loadNamesToComboBox();
    void MessageBox(QString title,QString text);

private:
    QStackedWidget *stackedWidget;
    QWidget *screen0;
    QWidget *screen1;
    Ui::MainWindow *uiMainWindow;
    Ui::Form1 *uiForm1;

    QSqlDatabase db;  // データベース接続オブジェクト

    void setupDatabase();          // データベースをセットアップする関数
    void saveNameToDatabase(const QString &name);     // 名前をデータベースに保存する関数

};

#endif // MAINWINDOW_H
