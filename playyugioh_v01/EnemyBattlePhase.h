#ifndef ENEMYBATTLEPHASE_H
#define ENEMYBATTLEPHASE_H

#include <QObject>
#include <QWidget>
#include <QListWidget>

class EnemyBattlePhase : public QObject{
    Q_OBJECT

public:
    explicit EnemyBattlePhase(QObject *parent = nullptr);
    void setHandListWidget(QListWidget *widget);
    void execute();

private slots:
    void onCardClicked(QListWidgetItem *item);

private:
    QListWidget *handListWidget;
    int fieldIndex;
};

#endif // ENEMYBATTLEPHASE_H
