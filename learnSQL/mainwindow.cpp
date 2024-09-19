#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // SQLiteデータベース接続設定
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("names.db");  // データベースファイル名
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    // テーブルが存在しない場合、作成する
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS names (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");

    // ボタン押下時の処理
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onSaveButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSaveButtonClicked()
{
    QString name = ui->lineEdit->text();  // 入力された名前を取得

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "名前を入力してください！");
        return;
    }

    // SQLにデータを挿入する
    QSqlQuery query;
    query.prepare("INSERT INTO names (name) VALUES (:name)");
    query.bindValue(":name", name);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "名前が保存されました！");
        ui->lineEdit->clear();  // 入力欄をクリア
    }
}
