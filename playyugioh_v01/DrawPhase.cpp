#include "DrawPhase.h"
#include <QListWidget>
#include <random>
#include <QDebug>

DrawPhase::DrawPhase(QObject *parent) :
    QObject(parent),
    handListWidget(nullptr)
    {
}

void DrawPhase::execute(){
    qDebug() << "Executing Draw Phase actions...";
    addCards();
}

void DrawPhase::addCards(){
    // 乱数生成のためのエンジンと分布を設定
    static std::random_device rd;//非決定的乱数生成器
    static std::mt19937 gen(rd());// メルセンヌ・ツイスタ
    std::uniform_int_distribution<> dis(1,100);//1から100の乱数を生成

    int randomNum = dis(gen);
    QString cardName = QString("Card %1").arg(randomNum);//カード名を生成
    if(handListWidget){
        handListWidget->addItems(handCards);
    }
    if (handListWidget) {
        // カードを手札に追加
        handListWidget->addItem(cardName);
    }
    qDebug() << "Hand Cards: " << handCards;
}

void DrawPhase::setHandListWidget(QListWidget *widget){
    handListWidget = widget;
}
