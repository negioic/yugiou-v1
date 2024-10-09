#ifndef BATTLEPHASE_H
#define BATTLEPHASE_H

#include <QObject>
#include <QWidget>
#include <QListWidget>

class BattlePhase : public QObject{
    Q_OBJECT

public:
    explicit BattlePhase(QObject *parent = nullptr);
    void setHandListWidget(QListWidget *widget);
    void execute();

private slots:
    void onCardClicked(QListWidgetItem *item);

private:
    QListWidget *handListWidget;
    int fieldIndex;
};

#endif // BATTLEPHASE_H
