#ifndef ENEMYSTANDBYPHASE_H
#define ENEMYSTANDBYPHASE_H

#include <QObject>

class EnemyStandbyPhase : public QObject{
    Q_OBJECT;

public:
    EnemyStandbyPhase(QObject *parent = nullptr);
    void execute();
};

#endif // ENEMYSTANDBYPHASE_H
