#ifndef SAVEWINDOW_H
#define SAVEWINDOW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class SaveWindow; }
QT_END_NAMESPACE

class SaveWindow : public QWidget
{
    Q_OBJECT

public:
    SaveWindow(QWidget *parent = nullptr);
    ~SaveWindow();

private:
    Ui::SaveWindow *ui;
    QSqlDatabase db;  // データベース用のメンバー変数

    bool createConnection();      // データベース接続用の関数
    bool createNameTable();       // テーブル作成用の関数
    bool createAttackerTable();   //　テーブル作成用の関数
    void loadNamesFromDatabase();   //デッキの名前をデータベースからロード
    void saveNameToDatabase(const QString &name);   // デッキの名前をデータベースに保存する関数
    void saveAttackerSideToDatabase(const QString &answer); // データベースに攻撃サイドを格納関数

private slots:
    void on_saveButton_clicked(); // 保存ボタンがクリックされたときのスロット
    void radioButton_First_clicked();
    void radioButton_Second_clicked();
};

#endif // SAVEWINDOW_H
