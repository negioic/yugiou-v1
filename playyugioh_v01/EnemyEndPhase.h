#ifndef ENEMYENDPHASE_H
#define ENEMYENDPHASE_H

#include <QObject>

class EnemyEndPhase : public QObject{
    Q_OBJECT

public:
    EnemyEndPhase(QObject *parent = nullptr);
    void execute();
};
#endif // ENEMYENDPHASE_H
