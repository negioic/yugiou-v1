#ifndef ENEMYMAINPHASE_H
#define ENEMYMAINPHASE_H

#include <QObject>
#include <QWidget>
#include <QListWidget>

class EnemyMainPhase : public QObject{
    Q_OBJECT

public:
    EnemyMainPhase(QObject *parent = nullptr);
    void execute();
    void setHandListWidget(QListWidget *widget);
    void setFieldListWidget(QListWidget *widget, int index);
    void onCardClicked(QListWidgetItem *item);

private:
    QListWidget *handListWidget;
    QList<QListWidget*> fieldListWidgets; // フィールドウィジェットを管理する配列
    int fieldIndex;
};

#endif
