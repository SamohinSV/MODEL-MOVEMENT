#include "integration.h"
#include <math.h>

Integration::Integration(int n, float intStep)
{
    this->N  = n;
    this->intStep = intStep;

    OutAccur = intStep/100;

    for (auto &i : m_data)
        i.resize (n);

    m_KeysBand.CreateAccuracy (OutAccur);
}

void Integration::Integrate(float *t)
{  
    nums num = First;
    m_t = t;

    float dr_t;
    modf(*t/intStep,&dr_t);
    float m_dt = intStep * (1 - dr_t);

    SwitchKey ();

    bool Tolerance = false;
    do {
        do {
            m_data[2] = m_data[0];
            RK_4(m_dt);
            SwitchKey ();

            m_KeysSet.resize (0);
            m_KeysBand.CheckSwitches (m_KeysSet);


            if (num == First && m_KeysSet.size () == 0) {
                num = Second;
            }
            else {
                num = Another;
            }

            if (num == Second) {
                m_dt = intStep;
            }
        } while (!(m_KeysSet.size () == 0));

        Tolerance = true;
        float e = 1;

        for (auto const &i:m_KeysSet) {
            Tolerance = Tolerance && m_KeysBand.CheckAccuracyN (i);

            float ei = m_KeysBand.getE (i);
            if (ei < e)
                e = sqrt (e*ei);
        }

        if (!Tolerance){
            *m_t = *m_t - m_dt;
            m_dt = e * m_dt;
            m_data[0] = m_data[2];
            m_KeysBand.FallBackSwitch_F();
        }

    } while (Tolerance);
}

void Integration::RK_4(const float &dt)
{
    float a[5];
    a[0] = dt/2;
    a[1] = dt/2;
    a[2] = dt;
    a[3] = dt;
    a[4] = dt/2;

    QVector<float> Va;
    QVector<float> Vr;

    Va.resize (N);
    Vr.resize (N);

    m_data[1] = m_data[0];
    Va = m_data[0];

    float t_s = 0.0;

    for (int i = 0; i <= 3; i++) {
        RightSideDif(Va,Vr);
        float b = a[i+1]/3;
        t_s = *m_t+a[i];

        for (int j = 0;  j<N; j++) {
            m_data[0][j] = m_data[0][j] + b * Vr[j];
            Va[i]        = m_data[2][j] + t_s * Vr[j];
        }
    }

    *m_t = t_s;
}


