#ifndef BASEPHASE_H
#define BASEPHASE_H

#include <QObject>

class BasePhase : public QObject {
    Q_OBJECT

public:
    explicit BasePhase(QObject *parent = nullptr) : QObject(parent) {}
    virtual void execute() = 0; // 各フェーズで実装する純粋仮想関数
};

#endif // BASEPHASE_H

