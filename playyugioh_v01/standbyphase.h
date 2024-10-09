#ifndef STANDBYPHASE_H
#define STANDBYPHASE_H

#include <QObject>

class StandbyPhase : public QObject{
    Q_OBJECT;

public:
    StandbyPhase(QObject *parent = nullptr);
    void execute();
};

#endif // STANDBYPHASE_H
