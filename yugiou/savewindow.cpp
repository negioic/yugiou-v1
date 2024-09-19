#include "savewindow.h"
#include "ui_savewindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

SaveWindow::SaveWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SaveWindow)
{
    ui->setupUi(this);

    // データベース接続とテーブル作成
    if (!createConnection() || !createNameTable() || !createAttackerTable()) { // テーブル作成の呼び出しを追加
        QMessageBox::critical(this, "Database Error", "Failed to setup database.");
        return;
    }

    // 保存された名前を読み込む
    loadNamesFromDatabase();

    // 保存ボタンのクリックを接続
    connect(ui->saveButton, &QPushButton::clicked, this, &SaveWindow::on_saveButton_clicked);

    connect(ui->radioButton_First, &QPushButton::clicked, this, &SaveWindow::radioButton_First_clicked);
    connect(ui->radioButton_Second, &QPushButton::clicked, this, &SaveWindow::radioButton_Second_clicked);

}

SaveWindow::~SaveWindow()
{
    delete ui;
}

bool SaveWindow::createConnection() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("yugioh_database.db");

    if (!db.open()) {
        qDebug() << "Database connection failed:";
        qDebug() << db.lastError();
        return false;
    }
    return true;
}

bool SaveWindow::createNameTable() {
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS names ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "name TEXT NOT NULL"
                  ")");
    if (!query.exec()) {
        qDebug() << "Error creating names table:";
        qDebug() << query.lastError();
        return false;
    }
    return true;
}

void SaveWindow::saveNameToDatabase(const QString &name) {
    QSqlQuery query;
    query.prepare("INSERT INTO names (name) VALUES (:name)");
    query.bindValue(":name", name);

    if (!query.exec()) {
        qDebug() << "Error saving name to database:";
        qDebug() << query.lastError();
    } else {
        qDebug() << "Name saved successfully";
    }
}

void SaveWindow::loadNamesFromDatabase() {
    QSqlQuery query;
    query.prepare("SELECT name FROM names");

    if (query.exec()) {
        while (query.next()) {
            QString name = query.value(0).toString();
            ui->comboBox_DecknameMine->addItem(name);
            ui->comboBox_DecknameEnemy->addItem(name);
        }
    } else {
        qDebug() << "Error loading names from database:";
        qDebug() << query.lastError();
    }
}

void SaveWindow::on_saveButton_clicked() {
    QString name = ui->nameInput->text();
    if (!name.isEmpty()) {
        saveNameToDatabase(name);
        ui->comboBox_DecknameMine->addItem(name);
        ui->comboBox_DecknameEnemy->addItem(name);
        ui->nameInput->clear(); // 入力フィールドをクリア
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a name.");
    }
}

void SaveWindow::radioButton_First_clicked() {
    saveAttackerSideToDatabase("First");
}

void SaveWindow::radioButton_Second_clicked() {
    saveAttackerSideToDatabase("Second");
}

void SaveWindow::saveAttackerSideToDatabase(const QString &answer) {
    QSqlQuery query;
    query.prepare("INSERT INTO attackersides (attackerside) VALUES (:attackerside)");
    query.bindValue(":attackerside", answer);

    if (!query.exec()) {
        qDebug() << "Error saving attacker to database:";
        qDebug() << query.lastError();
    } else {
        qDebug() << "Attacker saved successfully: " << answer;
    }
}


bool SaveWindow::createAttackerTable() {
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS attackersides ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "attackerside TEXT NOT NULL"
                  ")");
    if (!query.exec()) {
        qDebug() << "Error creating answers table:";
        qDebug() << query.lastError();
        return false;
    }
    return true;
}


