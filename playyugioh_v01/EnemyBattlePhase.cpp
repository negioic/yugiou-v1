#include "EnemyBattlePhase.h"
#include <QDebug>

EnemyBattlePhase::EnemyBattlePhase(QObject *parent)
    : QObject(parent),
    handListWidget(nullptr),
    fieldIndex(0) {
    // その他の初期化
}

void EnemyBattlePhase::setHandListWidget(QListWidget *widget) {
    handListWidget = widget;

    // ダブルクリックシグナルを無効にする
    if (handListWidget) {
        disconnect(handListWidget, &QListWidget::itemDoubleClicked, nullptr, nullptr);
        qDebug() << "Double-click signal disconnected in Battle Phase.";
        // ここで新たに接続しないことで、ダブルクリックが無効になる
    }
}

void EnemyBattlePhase::execute() {
    qDebug() << "Executing Battle Phase actions...";
    // ここでダブルクリックの接続を再確認し、無効にする
    if (handListWidget) {
        disconnect(handListWidget, &QListWidget::itemDoubleClicked, nullptr, nullptr);
        qDebug() << "Double-click signal disconnected in Battle Phase.";
    }
}

void EnemyBattlePhase::onCardClicked(QListWidgetItem *item) {
    // このメソッドは何もしないか、あるいはメッセージを表示しても良い
    qDebug() << "Card clicked in Battle Phase (no action performed).";
}
