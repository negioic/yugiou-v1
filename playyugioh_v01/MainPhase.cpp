#include "MainPhase.h"
#include <QDebug>
#include <QMessageBox>

MainPhase::MainPhase(QObject *parent) :
    QObject(parent)
    ,handListWidget(nullptr)
    ,fieldIndex(0)
{
    fieldListWidgets = {nullptr, nullptr, nullptr, nullptr, nullptr};
}

void MainPhase::execute(){
    qDebug() << "Executing Main Phase actions...";

    if(handListWidget){
        disconnect(handListWidget, &QListWidget::itemDoubleClicked, this, &MainPhase::onCardClicked);
        bool connected = connect(handListWidget, &QListWidget::itemDoubleClicked, this, &MainPhase::onCardClicked);
        qDebug() << "Connect result:" << connected;

    }
}

void MainPhase::setHandListWidget(QListWidget *widget){
    handListWidget = widget;
}

void MainPhase::setFieldListWidget(QListWidget *widget, int index){
    if (index >= 0 && index < fieldListWidgets.size()) {
        fieldListWidgets[index] = widget; // インデックスを指定してウィジェットを設定
    }
}

void MainPhase::onCardClicked(QListWidgetItem *item){
    if(handListWidget && fieldListWidgets[fieldIndex]){
        //確認メッセージボックスを表示
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(nullptr,"Confirm Summon",
                                      QString("Do you want to summon %1").arg(item->text()),
                                      QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
            // すでにカードが配置されている場合は追加しない
            if (fieldListWidgets[fieldIndex]->count() > 0) {
                QMessageBox::warning(nullptr, "Cannot Summon",
                                     QString("Cannot summon to %1. This spot is already occupied.")
                                         .arg(fieldIndex + 1)); // インデックスは1から始まるように表示
                return; // 追加しない
            }
            //フィールドにカードを追加
            fieldListWidgets[fieldIndex]->addItem(item->text());
            delete item;
            qDebug() << item->text() << "summoned to the field";

            fieldIndex = (fieldIndex + 1) % fieldListWidgets.size();
        } else {
            qDebug() << item-> text() << "not summoned";
        }
    }
}
