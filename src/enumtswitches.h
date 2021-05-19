#ifndef ENUMTSWITCHES_H
#define ENUMTSWITCHES_H

#include "tswitches.h"
#include "QVector"
#include "QString"

class EnumTSwitches
{
public:
    EnumTSwitches();

    void CreateAccuracy(float accar);

    void AdvanceSwitch_F();
    void FallBackSwitch_F();

    void CheckSwitches(QVector<int> &KeysSet);
    bool CheckAccuracyN(int i);

    float getE(int i);

    int length();

private:
    QVector<QString> Keys {"Final_time"};
    QVector<TSwitches> KeysBand;
};

#endif // ENUMTSWITCHES_H
