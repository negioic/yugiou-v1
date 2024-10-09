#ifndef ENDPHASE_H
#define ENDPHASE_H

#include <QObject>

class EndPhase : public QObject{
    Q_OBJECT

public:
    EndPhase(QObject *parent = nullptr);
    void execute();
};
#endif // ENDPHASE_H
