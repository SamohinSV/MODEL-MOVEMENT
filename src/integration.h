#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <QVector>
#include <QString>
#include "tswitches.h"

class Integration
{
public:
    explicit Integration(int number, float step, QVector<QString> keys);
    virtual ~Integration();

    void Integrate (float *time);

private:
    enum nums {First, Second, Another};

    void FallBackSwitches();
    void AdvanceSwitches();
    void Runge_Kutta_4(const float &dt);

    virtual void RightSideDif(QVector<float> &resultValue , QVector<float> &diffValue) = 0;
    virtual void SwitchKey () = 0;

    float *m_time;
    float m_step;
    float OutAccur;
    int   m_number;
    QVector<int>       m_KeysSet;
    QVector<TSwitches> m_KeysBand;
    QVector<float>     m_data[3];
};

#endif // INTEGRATION_H
