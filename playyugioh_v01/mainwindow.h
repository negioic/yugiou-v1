#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QVector>

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

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onButtonClicked();

private:
    Ui::MainWindow *ui;
    QStringList buttonNames;    // フェーズボタンの名前リスト
    int currentIndex;           // 現在のフェーズのインデックス

    GameStart *gameStart;   //ゲーム開始クラス

    BasePhase *basePhase;
    // プレイヤーのフェーズ
    StandbyPhase *standbyPhase;
    DrawPhase *drawPhase;
    MainPhase *mainPhase;
    BattlePhase *battlePhase;
    EndPhase *endPhase;

    // 敵のフェーズ
    EnemyStandbyPhase *enemyStandbyPhase;
    EnemyDrawPhase *enemyDrawPhase;
    EnemyMainPhase *enemyMainPhase;
    EnemyBattlePhase *enemyBattlePhase;
    EnemyEndPhase *enemyEndPhase;

    // フェーズのリスト管理用
    QList<QObject*> phases;               // 全フェーズをまとめたリスト

    void someFunction();
    void initializeDatabase();
};
#endif // MAINWINDOW_H
