#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "GameStart.h"
#include "BasePhase.h"
#include "CardInfo.h"

#include "StandbyPhase.h"
#include "DrawPhase.h"
#include "MainPhase.h"
#include "BattlePhase.h"
#include "EndPhase.h"

#include "EnemyStandbyPhase.h"
#include "EnemyDrawPhase.h"
#include "EnemyMainPhase.h"
#include "EnemyBattlePhase.h"
#include "EnemyEndPhase.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameStart(new GameStart(this))
    //, basePhase(new BasePhase(this))
    , standbyPhase(new StandbyPhase(this))
    , drawPhase(new DrawPhase(this))
    , mainPhase(new MainPhase(this))
    , battlePhase(new BattlePhase(this))
    , endPhase(new EndPhase(this))
    , enemyStandbyPhase(new EnemyStandbyPhase(this))
    , enemyDrawPhase(new EnemyDrawPhase(this))
    , enemyMainPhase(new EnemyMainPhase(this))
    , enemyBattlePhase(new EnemyBattlePhase(this))
    , enemyEndPhase(new EnemyEndPhase(this))
{
    ui->setupUi(this);

    // ゲーム開始時に手札を生成
    gameStart->initializeGame(ui->handlistWidget, ui->enemyHandlistWidget);

    drawPhase->setHandListWidget(ui->handlistWidget);//手札を表示するQListWidgetをDrawPhaseに設定
    mainPhase->setHandListWidget(ui->handlistWidget);//MainPhase用の手札ウィジェット
    battlePhase->setHandListWidget(ui->handlistWidget);

    enemyDrawPhase->setHandListWidget(ui->enemyHandlistWidget);
    enemyMainPhase->setHandListWidget(ui->enemyHandlistWidget);
    enemyBattlePhase->setHandListWidget(ui->enemyHandlistWidget);

    //フィールド用ウィジェットを配列に格納
    QList<QListWidget*> fieldWidgets = { ui->monsterWidget1,ui->monsterWidget2,ui->monsterWidget3,ui->monsterWidget4,ui->monsterWidget5};
    for (int i = 0; i < fieldWidgets.size(); ++i) {
        mainPhase->setFieldListWidget(fieldWidgets[i], i); // インデックスを渡す
    }
    // 相手フィールド用ウィジェットを配列に格納
    QList<QListWidget*> enemyFieldWidgets = { ui->enemymonsterWidget1, ui->enemymonsterWidget2, ui->enemymonsterWidget3, ui->enemymonsterWidget4, ui->enemymonsterWidget5 };
    for (int i = 0; i < enemyFieldWidgets.size(); ++i) {
        enemyMainPhase->setFieldListWidget(enemyFieldWidgets[i], i); // インデックスを渡す
    }

    standbyPhase->execute();//起動時にstandbyphaseを実行

    //ボタンの名前
    buttonNames << "Standby Phase" <<"Draw Phase" << "Main Phase" << "Battle Phase" << "End Phase"
                << "Enemy Standby Phase" <<"Enemy Draw Phase" << "Enemy Main Phase" << "Enemy Battle Phase" << "Enemy End Phase";
    ui->pushButton->setText(buttonNames[currentIndex]);
    connect(ui->pushButton,&QPushButton::clicked, this, &MainWindow::onButtonClicked);
    initializeDatabase();
    someFunction();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked() {
    currentIndex = (currentIndex + 1) % buttonNames.size();
    ui->pushButton->setText(buttonNames[currentIndex]);

    // フェーズの実行をリストで管理
    QList<QObject*> phases = { standbyPhase, drawPhase, mainPhase, battlePhase, endPhase,
                               enemyStandbyPhase, enemyDrawPhase, enemyMainPhase, enemyBattlePhase, enemyEndPhase };

    // currentIndexを使用して適切なフェーズのexecuteメソッドを呼び出す
    if (currentIndex < phases.size() && phases[currentIndex] != nullptr) {
        switch (currentIndex) {
        case 0: // Standby Phase
            static_cast<StandbyPhase*>(phases[currentIndex])->execute();
            break;
        case 1: // Draw Phase
            static_cast<DrawPhase*>(phases[currentIndex])->execute();
            break;
        case 2: // Main Phase
            static_cast<MainPhase*>(phases[currentIndex])->execute();
            break;
        case 3: // Battle Phase
            static_cast<BattlePhase*>(phases[currentIndex])->execute();
            break;
        case 4: // End Phase
            static_cast<EndPhase*>(phases[currentIndex])->execute();
            break;
        case 5: // Enemy Standby Phase
            static_cast<EnemyStandbyPhase*>(phases[currentIndex])->execute();
            break;
        case 6: // Enemy Draw Phase
            static_cast<EnemyDrawPhase*>(phases[currentIndex])->execute();
            break;
        case 7: // Enemy Main Phase
            static_cast<EnemyMainPhase*>(phases[currentIndex])->execute();
            break;
        case 8: // Enemy Battle Phase
            static_cast<EnemyBattlePhase*>(phases[currentIndex])->execute();
            break;
        case 9: // Enemy End Phase
            static_cast<EnemyEndPhase*>(phases[currentIndex])->execute();
            break;
        default:
            break;
        }
    }
}

void MainWindow::initializeDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("cards.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
        return;
    }

    QSqlQuery query;
    QString createTable = "CREATE TABLE IF NOT EXISTS cards ("
                          "id INTEGER PRIMARY KEY, "
                          "name TEXT, "
                          "attack INTEGER, "
                          "defense INTEGER)";

    if (!query.exec(createTable)) {
        qDebug() << "Failed to create table:" << query.lastError().text();
    } else {
        qDebug() << "Table created or already exists!";
    }
}


void MainWindow::someFunction() {
    // カードを作成してデータベースに保存
    CardInfo newCard(1, "Blue-Eyes White Dragon", 3000, 2500);
    newCard.saveToDatabase();

    // カードをデータベースから読み込む
    CardInfo loadedCard = CardInfo::loadFromDatabase(1);
    qDebug() << "Loaded card:" << loadedCard.getName();
}
