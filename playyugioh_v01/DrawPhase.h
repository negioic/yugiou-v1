#ifndef DRAWPHASE_H
#define DRAWPHASE_H

#include <QWidget>
#include <QObject>
#include <QListWidget>
#include <QVector>

class DrawPhase : public QObject{
    Q_OBJECT

public:
    DrawPhase(QObject *parent = nullptr);
    void execute();

    void setHandListWidget(QListWidget *widget);//手札を表示するウィジェットを設定

private:
    QVector<QString> handCards;//手札を保持
    void addCards();

    QListWidget *handListWidget; //手札を表示するウィジェット
};

#endif // DRAWPHASE_H
