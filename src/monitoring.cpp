#include "monitoring.h"
#include "QVector"
#include "QString"

Monitoring::Monitoring(QObject *parent) : QObject(parent)
{
    QVector<QString> kes;
    kes.push_back ("Finish_time");
    m_point = new Body_integration(2,0.01f,kes);
}

Monitoring::~Monitoring()
{
    delete  m_point;
}

void Monitoring::start()
{
    m_point->calculation ();
}
