#ifndef BODY_INTEGRATION_H
#define BODY_INTEGRATION_H

#include "integration.h"
#include "solid.h"

class Body_integration:public Integration
{
public:
    Body_integration(int n, float intStep, QVector<QString> keys);
    ~Body_integration() override;

    void calculation();
private:
    void RightSideDif(QVector<float> &a, QVector<float> &r) override;
    void SwitchKey (QVector<TSwitches> &KeysBand) override;

    Solid m_d;
};

#endif // BODY_INTEGRATION_H
