#ifndef TSWITCHES_H
#define TSWITCHES_H

#include <QString>

class TSwitches
{
public:
    TSwitches();
    void AdvanceSwitch_F();
    void FallBackSwitch_F();
    void SetKey(QString name);
    void SetAccuracy(float Accur);

    float GetE();
    bool CheckSign();
    bool CheckAccuracy();
private:
    QString Key;
    float   Switch_F[2];
    float   Accuracy;
    float   AppearTime;
    bool    Enabled;
    bool    Happened;

};

#endif // TSWITCHES_H
