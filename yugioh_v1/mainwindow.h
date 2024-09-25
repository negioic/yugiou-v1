#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "ui_mainwindow.h"
#include "ui_form1.h"
#include "ui_form2.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void GoToScreen0();
    void GoToScreen1();
    void GoToScreen2();
    void onSaveButton1Clicked();  // 名前を保存するボタンのクリック時の処理
    void onSaveButton2Clicked();
    void loadNamesToComboBox();
    void MessageBox(QString title,QString text);

private:
    QStackedWidget *stackedWidget;
    QWidget *screen0;
    QWidget *screen1;
    QWidget *screen2;
    Ui::MainWindow *uiMainWindow;
    Ui::Form1 *uiForm1;
    Ui::Form2 *uiForm2;
    QSqlDatabase db;  // データベース接続オブジェクト
    QButtonGroup *buttonGroup1;  // 追加
    QButtonGroup *buttonGroup2;  // 追加
    void setupDatabase();          // データベースをセットアップする関数
    void saveNameToDatabase(const QString &name);     // 名前をデータベースに保存する関数
    void displayData();

};

#endif // MAINWINDOW_H
