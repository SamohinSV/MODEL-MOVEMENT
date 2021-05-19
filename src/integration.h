#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <QVector>
#include <QString>
#include "enumtswitches.h"

class Integration
{
    float *m_t; // Time
    float intStep;
    float OutAccur;// точность переключения
    int N;// число диффиренцальных уравнений
    QVector<int> m_KeysSet;
    EnumTSwitches m_KeysBand;
    QVector<float> m_data[3];
public:
    Integration(int n, float intStep);
    virtual ~Integration();

    void Integrate (float *t);

private:
    enum nums {First, Second, Another};

    virtual void RightSideDif(QVector<float> &a, QVector<float> &r) = 0;
    virtual void SwitchKey () = 0;

    void RK_4(const float &dt);
};

#endif // INTEGRATION_H
