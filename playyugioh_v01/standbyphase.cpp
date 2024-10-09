#include "StandbyPhase.h"
#include <QDebug>

StandbyPhase::StandbyPhase(QObject *parent) : QObject(parent){}

void StandbyPhase::execute(){
    qDebug() << "Executing Standby Phase actions...";
}
