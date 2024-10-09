#ifndef MAINPHASE_H
#define MAINPHASE_H

#include <QObject>
#include <QWidget>
#include <QListWidget>

class MainPhase : public QObject{
    Q_OBJECT

public:
    MainPhase(QObject *parent = nullptr);
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
