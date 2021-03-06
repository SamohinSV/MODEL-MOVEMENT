#ifndef BODY_INTEGRATION_H
#define BODY_INTEGRATION_H

#include "integration.h"
#include "solid.h"

class Body_integration:public Integration
{
public:
    explicit Body_integration(int n, float intStep, QVector<QString> keys);
    ~Body_integration() override;

    void calculation();
private:
    void RightSideDif(QVector<float> &result, QVector<float> &Dif) override;
    void SwitchKey (QVector<TSwitches> &KeysBand) override;

    Solid m_d;
};

#endif // BODY_INTEGRATION_H
