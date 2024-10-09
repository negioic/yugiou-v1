#include "EnemyStandbyPhase.h"
#include <QDebug>

EnemyStandbyPhase::EnemyStandbyPhase(QObject *parent) : QObject(parent){}

void EnemyStandbyPhase::execute(){
    qDebug() << "Executing Standby Phase actions...";
}
