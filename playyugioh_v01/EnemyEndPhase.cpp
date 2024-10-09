#include "EnemyEndPhase.h"
#include <QDebug>

EnemyEndPhase::EnemyEndPhase(QObject *parent) : QObject(parent){}

void EnemyEndPhase::execute(){
    qDebug() << "Executing End Phase actions...";
}
