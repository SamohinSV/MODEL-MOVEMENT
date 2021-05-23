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
    void SetSwitch_F(float x);
    void SetEnabled(bool B);
    void CheckFinish();

    bool CheckSign();
    bool CheckAccuracy();
    float GetE();
    QString GetKey();
    bool GetEnabled();
private:
    float Switch_F[2];
    QString Key;
    float Accuracy;
    bool Enabled;
    bool Happened;

};

#endif // TSWITCHES_H
