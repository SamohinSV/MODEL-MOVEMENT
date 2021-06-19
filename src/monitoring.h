#ifndef MONITORING_H
#define MONITORING_H

#include <QObject>
#include "body_integration.h"

class Monitoring : public QObject
{
    Q_OBJECT
public:
    explicit Monitoring(QObject *parent = nullptr);
    ~Monitoring();
    Q_INVOKABLE void start();
signals:

public slots:

public:
    Body_integration *m_point;
};

#endif // MONITORING_H
