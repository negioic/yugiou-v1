#ifndef ENEMYDRAWPHASE_H
#define ENEMYDRAWPHASE_H

#include <QWidget>
#include <QObject>
#include <QListWidget>
#include <QVector>

class EnemyDrawPhase : public QObject{
    Q_OBJECT

public:
    EnemyDrawPhase(QObject *parent = nullptr);
    void execute();

    void setHandListWidget(QListWidget *widget);//手札を表示するウィジェットを設定

private:
    QVector<QString> enemyHandCards;//手札を保持
    void addCards();

    QListWidget *enemyHandListWidget; //手札を表示するウィジェット
};

#endif // ENEMYDRAWPHASE_H
