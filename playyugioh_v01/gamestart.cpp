#include "GameStart.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QDebug>

GameStart::GameStart(QObject *parent) :
    QObject(parent)
{
}

void GameStart::initializeGame(QListWidget *playerHandWidget, QListWidget *enemyHandWidget) {
    // プレイヤーの手札を生成
    generateHand(playerHandWidget, 5, "Player Card");

    // 敵の手札を生成
    generateHand(enemyHandWidget, 5, "Enemy Card");
}

void GameStart::generateHand(QListWidget *handWidget, int numCards, const QString &cardPrefix) {
    // 安全のため、手札が空であることを確認してから生成
    if (!handWidget) return;

    handWidget->clear();  // 古い手札をクリア
    for (int i = 0; i < numCards; ++i) {
        QListWidgetItem *newCard = new QListWidgetItem(cardPrefix + " " + QString::number(i + 1));
        handWidget->addItem(newCard);
    }
}
