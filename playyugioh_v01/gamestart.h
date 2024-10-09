#ifndef GAMESTART_H
#define GAMESTART_H

#include <QWidget>
#include <QObject>
#include <QListWidget>


class GameStart : public QObject{
    Q_OBJECT

public:
    GameStart(QObject *parent = nullptr);
    //ゲームの初期化
    void initializeGame(QListWidget *playerHandWidget, QListWidget *enemyHandWidget);

private:
    //手札を生成
    void generateHand(QListWidget *handWidget, int numCards, const QString &cardPrefix);
};


#endif // GAMESTART_H
