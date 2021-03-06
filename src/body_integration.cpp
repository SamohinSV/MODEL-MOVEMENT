#include "body_integration.h"

Body_integration::Body_integration(int n, float intStep, QVector<QString> keys):
    Integration (n,intStep,keys)
{

}

Body_integration::~Body_integration()
{

}

void Body_integration::calculation()
{
    QVector<QString> finalCase;
    finalCase.push_back("Finish_time");

    do {
      Integrate (&m_d.time);

    } while (FinalIntegrate(finalCase));

}

void Body_integration::RightSideDif(QVector<float> &result, QVector<float> &Dif)
{
    m_d.x  = result[0];
    m_d.dx = result[1];

    Dif[0] = m_d.dx;
    Dif[1] = 1;
}

void Body_integration::SwitchKey(QVector<TSwitches> &KeysBand)
{
    AdvanceSwitches ();

    for (auto &m :KeysBand) {

        if (m.GetKey () == "Finish_time") {
            m.SetEnabled (true);
            m.SetSwitch_F(m_d.time - 0.5);
        }
       m.CheckFinish();
    }
}
