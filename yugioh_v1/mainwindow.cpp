#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_form1.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) ,

    // スタックウィジェットを作成
    stackedWidget(new QStackedWidget(this)),
    screen0(new QMainWindow(this)),
    screen1(new QMainWindow(this)),
    uiMainWindow(new Ui::MainWindow),
    uiForm1(new Ui::Form1)
{
    qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    setCentralWidget(stackedWidget);

    // Form1のUIをセットアップ
    uiMainWindow->setupUi(static_cast<QMainWindow*>(screen0));
    // Form2のUIをセットアップ
    uiForm1->setupUi(static_cast<QMainWindow*>(screen1));

    // スタックウィジェットに画面を追加
    stackedWidget->addWidget(screen0);
    stackedWidget->addWidget(screen1);

    // デフォルトで画面1を表示
    stackedWidget->setCurrentWidget(screen0);

    // ボタンクリック時に画面を切り替える
    connect(uiMainWindow->pushButton, &QPushButton::clicked, this, &MainWindow::GoToScreen1);
    connect(uiForm1->pushButton, &QPushButton::clicked, this, &MainWindow::GoToScreen0);

    //ボタンクリック時に名前を保存
    connect(uiForm1->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveButtonClicked);

    setupDatabase();
    this->resize(800, 600);
}

MainWindow::~MainWindow()
{
    delete uiMainWindow;
    delete uiForm1;
}

void MainWindow::GoToScreen0()
{
    stackedWidget->setCurrentWidget(screen0);
}

void MainWindow::GoToScreen1()
{
    stackedWidget->setCurrentWidget(screen1);
}
void MainWindow::setupDatabase() {
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("names.db");

        if (!db.open()) {
            qDebug() << "Error: Could not open database." << db.lastError().text();
            QMessageBox::critical(this, "Database Error", "データベースを開けませんでした。");
            return;
        }
    }

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS names (id INTEGER PRIMARY KEY, name TEXT UNIQUE)")) {
        qDebug() << "Error creating table:" << query.lastError().text();
    } else {
        qDebug() << "Table created or already exists.";
    }

    loadNamesToComboBox();
}

void MainWindow::loadNamesToComboBox() {
    uiForm1->comboBox1->clear();
    uiForm1->comboBox2->clear();

    QSqlQuery query("SELECT name FROM names");
    while (query.next()) {
        QString name = query.value(0).toString();
        uiForm1->comboBox1->addItem(name);
        uiForm1->comboBox2->addItem(name);
    }
}

void MainWindow::onSaveButtonClicked() {
    QString name = uiForm1->lineEdit->text();  // QLineEditから名前を取得
    if (name.isEmpty()) {
        //QMessageBox::warning(this, "Input Error", "名前を入力してください！");
        /*QMessageBox msgBox0;
        msgBox0.setWindowTitle("Input Error");
        msgBox0.setText("名前を入力してください。");
        msgBox0.setIcon(QMessageBox::NoIcon);  // アイコンをなしに設定
        msgBox0.exec();*/
        MessageBox("Input Error","名前を入力してください。");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO names (name) VALUES (:name)");
    query.bindValue(":name", name);

    if (!query.exec()) {
        qDebug() << "Error inserting into database: " << query.lastError().text();
        //QMessageBox::critical(this, "Database Error", "名前を保存できませんでした。既に存在している可能性があります。");
        /*QMessageBox msgBox1;
        msgBox1.setWindowTitle("Database Error");
        msgBox1.setText("名前を保存できませんでした。既に存在している可能性があります。");
        msgBox1.setIcon(QMessageBox::NoIcon);  // アイコンをなしに設定
        msgBox1.exec();*/
        MessageBox("Database Error","名前を保存できませんでした。既に存在している可能性があります。");


    } else {
        qDebug() << "Name saved successfully!";
        //QMessageBox::information(this, "Success", "名前が保存されました！");
        /*MessageBox msgBox2;
        msgBox2.setWindowTitle("Success");
        msgBox2.setText("名前が保存されました！");
        msgBox2.setIcon(QMessageBox::NoIcon);  // アイコンをなしに設定
        msgBox2.exec();*/
        MessageBox("Success","名前が保存されました");

        uiForm1->comboBox1->addItem(name);
        uiForm1->comboBox2->addItem(name);
        uiForm1->lineEdit->clear();  // 入力フィールドをクリア
    }
}

void MainWindow::MessageBox(QString title,QString text) {
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.setIcon(QMessageBox::NoIcon);  // アイコンをなしに設定
    msgBox.exec();
}




