#include "integration.h"
#include <math.h>

Integration::Integration(int number, float step, QVector<QString> keys)
    :m_step(step),m_number(number)
{
    OutAccur = m_step/100;

    for (auto &i : m_data)
        i.resize (m_number);

    m_KeysBand.resize (keys.size ());

    for (int i = 0;i<m_KeysBand.size ();i++) {
        m_KeysBand[i].SetKey(keys[i]);
        m_KeysBand[i].SetAccuracy (OutAccur);
    }
}

Integration::~Integration()
{
    delete m_time;
}

void Integration::Integrate(float *time)
{
    nums num = First;
    m_time = time;

    float dr_t;
     modf(*m_time/m_step,&dr_t);
    float dtime = m_step * (1 - dr_t);

    SwitchKey (m_KeysBand);

    bool Tolerance = false;
    do {
        do {
            m_data[2] = m_data[0];

            Runge_Kutta_4(dtime);
            SwitchKey (m_KeysBand);

            m_KeysSet.resize (0);

            for (int i = 0; i <m_KeysBand.size (); i++) {
                if (m_KeysBand[i].CheckSign ())
                    m_KeysSet.push_back (i);
            }

            if (num == First && m_KeysSet.size () == 0)
                num = Second;
            else
                num = Another;

            if (num == Second)
                dtime = m_step;


        } while (!(m_KeysSet.size () == 0));

        Tolerance = true;
        float e = 1;

        for (auto const &i:m_KeysSet) {
            Tolerance = Tolerance && m_KeysBand[i].CheckAccuracy();

            float ei = m_KeysBand[i].GetE();

            if (ei < e)
                e = sqrt (e*ei);
        }

        if (!Tolerance) {
            *m_time   = *m_time - dtime;
            dtime     = e * dtime;
            m_data[0] = m_data[2];
            FallBackSwitches();
        }

    } while (Tolerance);
}

void Integration::FallBackSwitches()
{
    for(auto &n:m_KeysBand)
        n.FallBackSwitch_F();
}

void Integration::AdvanceSwitches()
{
    for(auto &n:m_KeysBand)
        n.AdvanceSwitch_F ();
}

bool Integration::FinalIntegrate(QVector<QString> nameKeys)
{
    for (auto i: nameKeys)
        for (int var = 0; m_KeysBand.size (); var++) {
            if (m_KeysBand[var].GetKey() == i)
                for (auto j:m_KeysSet)
                    if (j==var)
                        return true;
        }

    return false;
}

void Integration::Runge_Kutta_4(const float &dt)
{
    float a[5];
    a[0] = dt/2;
    a[1] = dt/2;
    a[2] = dt;
    a[3] = dt;
    a[4] = dt/2;

    QVector<float> v_resultValue;
    QVector<float> v_diffValue;

    v_resultValue.resize (m_number);
    v_diffValue.resize (m_number);

    m_data[1] = m_data[0];
    v_resultValue = m_data[0];

    float t_s = 0.0;

    for (int i = 0; i <= 3; i++) {
        RightSideDif(v_resultValue,v_diffValue);

        float b = a[i+1]/3;
        t_s = *m_time+a[i];

        for (int j = 0;  j<m_number; j++) {
            m_data[0][j]     = m_data[0][j] + b * v_diffValue[j];
            v_resultValue[i] = m_data[2][j] + t_s * v_diffValue[j];
        }
    }

    *m_time = t_s;
}
