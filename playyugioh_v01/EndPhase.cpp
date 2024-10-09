#include "EndPhase.h"
#include <QDebug>

EndPhase::EndPhase(QObject *parent) : QObject(parent){}

void EndPhase::execute(){
    qDebug() << "Executing End Phase actions...";
}
