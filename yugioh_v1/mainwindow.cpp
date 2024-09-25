#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_form1.h"
#include "ui_form2.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QButtonGroup>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) ,

    // スタックウィジェットを作成
    stackedWidget(new QStackedWidget(this)),
    screen0(new QMainWindow(this)),
    screen1(new QMainWindow(this)),
    screen2(new QMainWindow(this)),
    uiMainWindow(new Ui::MainWindow),
    uiForm1(new Ui::Form1),
    uiForm2(new Ui::Form2),
    buttonGroup1(new QButtonGroup(this)),  // グループ1
    buttonGroup2(new QButtonGroup(this))   // グループ2
{
    qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    setCentralWidget(stackedWidget);

    //UIをセットアップ
    uiMainWindow->setupUi(static_cast<QMainWindow*>(screen0));
    uiForm1->setupUi(static_cast<QMainWindow*>(screen1));
    uiForm2->setupUi(static_cast<QMainWindow*>(screen2));

    // スタックウィジェットに画面を追加
    stackedWidget->addWidget(screen0);
    stackedWidget->addWidget(screen1);
    stackedWidget->addWidget(screen2);

    // デフォルトで画面1を表示
    stackedWidget->setCurrentWidget(screen0);

    // ボタンクリック時に画面を切り替える
    connect(uiMainWindow->pushButton1, &QPushButton::clicked, this, &MainWindow::GoToScreen1);
    connect(uiMainWindow->pushButton2, &QPushButton::clicked, this, &MainWindow::GoToScreen2);
    connect(uiForm1->backmenuButton, &QPushButton::clicked, this, &MainWindow::GoToScreen0);
    connect(uiForm2->backmenuButton, &QPushButton::clicked, this, &MainWindow::GoToScreen0);

    connect(uiMainWindow->pushButton2, &QPushButton::clicked, this, &MainWindow::displayData);

    //ボタンクリック時に名前を保存
    connect(uiForm1->savedeckButton, &QPushButton::clicked, this, &MainWindow::onSaveButton1Clicked);
    connect(uiForm1->savedataButton, &QPushButton::clicked, this, &MainWindow::onSaveButton2Clicked);

    // ラジオボタングループを設定
    buttonGroup1->addButton(uiForm1->firstsecondButton1);
    buttonGroup1->addButton(uiForm1->firstsecondButton2);
    buttonGroup2->addButton(uiForm1->winloseButton1);
    buttonGroup2->addButton(uiForm1->winloseButton2);

    setupDatabase();
    this->resize(800, 600);
}

MainWindow::~MainWindow()
{
    delete uiMainWindow;
    delete uiForm1;
    delete uiForm2;
}

void MainWindow::GoToScreen0()  //スクリーンを変更
{
    stackedWidget->setCurrentWidget(screen0);
}

void MainWindow::GoToScreen1()  //スクリーンを変更
{
    stackedWidget->setCurrentWidget(screen1);
}

void MainWindow::GoToScreen2()  //スクリーンを変更
{
    stackedWidget->setCurrentWidget(screen2);
}

void MainWindow::setupDatabase() {  //データベースを読み込み
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("yugioudata2.db");

        if (!db.open()) {
            qDebug() << "Error: Could not open database." << db.lastError().text();
            QMessageBox::critical(this, "Database Error", "データベースを開けませんでした。");
            return;
        }
    }

    QSqlQuery query;
    //1つ目のテーブル
    if (!query.exec("CREATE TABLE IF NOT EXISTS names ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "name TEXT UNIQUE)")){
        qDebug() << "Error creating 'name' table:" << query.lastError().text();
    } else {
        qDebug() << "'name' table created or already exists.";
    }
    //2つ目のテーブル
    if (!query.exec("CREATE TABLE IF NOT EXISTS options ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "yourdeck TEXT, "
                    "enemydeck TEXT, "
                    "attackerside TEXT, "
                    "win_lose TEXT, "
                    "reason TEXT, "
                    "created_at DATETIME DEFAULT CURRENT_TIMESTAMP)")) {
        qDebug() << "Error creating 'options' table:" << query.lastError().text();
    } else {
        qDebug() << "'options' table created or already exists.";
    }
    loadNamesToComboBox();
}

void MainWindow::loadNamesToComboBox() {    //コンボボックスの値をSQLからデータを読み込んで出力
    uiForm1->yourdeckBox->clear();
    uiForm1->enemydeckBox->clear();

    QSqlQuery query("SELECT name FROM names");
    while (query.next()) {
        QString name = query.value(0).toString();
        uiForm1->yourdeckBox->addItem(name);
        uiForm1->enemydeckBox->addItem(name);
    }
}

void MainWindow::onSaveButton1Clicked() {    //セーブボタンを押したときにSQL保存、コンボボックスの値を変更
    QString name = uiForm1->lineEdit->text();  // QLineEditから名前を取得
    if (name.isEmpty()) {
        MessageBox("Input Error","名前を入力してください。");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO names (name) VALUES (:name)");
    query.bindValue(":name", name);

    if (!query.exec()) {
        qDebug() << "Error inserting into database: " << query.lastError().text();
        MessageBox("Database Error","名前を保存できませんでした。既に存在している可能性があります。");

    } else {
        qDebug() << "Name saved successfully!";
        MessageBox("Success","名前が保存されました");

        uiForm1->yourdeckBox->addItem(name);
        uiForm1->enemydeckBox->addItem(name);
        uiForm1->lineEdit->clear();  // 入力フィールドをクリア
    }
}

void MainWindow::onSaveButton2Clicked() {
    QString yourdeck;
    QString enemydeck;
    QString attackerside;
    QString winloseOption;
    QString reason;
    QSqlQuery query;
    query.prepare("INSERT INTO options (yourdeck, enemydeck, attackerside, win_lose, reason) VALUES (:yourdeck, :enemydeck, :attackerside, :win_lose, :reason)");

    //デッキの名前を確認
    yourdeck = uiForm1->yourdeckBox->currentText();
    enemydeck = uiForm1->enemydeckBox->currentText();

    // 前後の選択状態を確認
    if (uiForm1->firstsecondButton1->isChecked()) {
        attackerside = "First";
    } else if (uiForm1->firstsecondButton2->isChecked()) {
        attackerside = "Second";
    } else {
        MessageBox("Input Error", "いずれかのオプションを選択してください。");
        return;
    }

    //勝敗の選択状態を確認
    if (uiForm1->winloseButton1->isChecked()) {
        winloseOption = "Win";
    } else if (uiForm1->winloseButton2->isChecked()) {
        winloseOption = "Lose";
    } else {
        MessageBox("Input Error", "いずれかのオプションを選択してください。");
        return;
    }

    //勝敗の理由を確認
    reason = uiForm1->reasontextEdit->toPlainText();

    query.bindValue(":yourdeck", yourdeck);
    query.bindValue(":enemydeck", enemydeck);
    query.bindValue(":attackerside", attackerside);
    query.bindValue(":win_lose", winloseOption);
    query.bindValue(":reason", reason);
    if (!query.exec()) {
        qDebug() << "Error inserting into database: " << query.lastError().text();
        MessageBox("Database Error","データを保存できませんでした。データベースに問題があるようです。");

    } else {
        qDebug() << "Options saved successfully!";
        MessageBox("Success","データが保存されました");

    }
}

void MainWindow::MessageBox(QString title,QString text) {   //メッセージボックスで音を消して出力
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.setIcon(QMessageBox::NoIcon);  // アイコンをなしに設定
    msgBox.exec();
}

void MainWindow::displayData() {
    // データベースからのデータを挿入
    QSqlQuery rowCountQuery("SELECT COUNT(*) FROM options");
    rowCountQuery.next();
    int rowCount = rowCountQuery.value(0).toInt();

    // 行数を設定
    uiForm2->tableWidget->setRowCount(rowCount);
    uiForm2->tableWidget->setColumnCount(6);  // 列数は6列
    uiForm2->tableWidget->setHorizontalHeaderLabels({"Your Deck", "Enemy Deck", "Attacker Side", "Win/Lose", "Reason", "Created At"});

    // データベースからデータを取得してテーブルに挿入
    QSqlQuery query("SELECT yourdeck, enemydeck, attackerside, win_lose, reason, created_at FROM options");
    int row = 0;
    while (query.next()) {
        uiForm2->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        uiForm2->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        uiForm2->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        uiForm2->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        uiForm2->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        uiForm2->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        row++;
    }
}
