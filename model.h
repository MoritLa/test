#ifndef MODEL_H
#define MODEL_H

#include <QTimer>
#include "connectionmonitor.h"
#include "simulationscreen.h"

#include <stdint.h>

class Model: public QObject
{
    Q_OBJECT

    ConnectionMonitor *OutputInterface ;
    simulationScreen * OutputWindow ;
    QTimer timer ;

    bool simulate = 0 ;

    // Model parameters
    double TorqueSetpoint, TrueTorque ; //[Nm]
    double SpeedSetpoint, TrueSpeed ; //[rpm]
    double acceleration[3] ; //[m/s^2]
    double netSpeed ;   //[m/s]
    double steeringAngle ; //[rad] (right positive)
    double breakPedal ; //[-]
    double acceleratorPedal;//[-]
    double WheelSpeed[4] ; //[rpm]
    double WheelTorque[4] ;
    double OutputPower ;
    double StateOfCharge ;

    // Modle functions
    void NewTorque(void) ;
    void NewAcceleration(void) ;
    void NewWheelSpeed(void) ;

private slots:
    void UpdateStep(void) ;

public:
    Model(ConnectionMonitor *outputEmitter, simulationScreen *outputScreen);
    void init(void) ;
    void pause(void) ;

    void setBreakPedal(int newBreakPedal) ;
    void setAccelerationPedal(int newAccelerationPedal) ;
    void setSteeringAngle(int newSteeringAngle) ;

    void setSpeedSetpoint(int16_t speedSetpoint);
    void setTorqueSetpoint(int16_t torqueSetpoint) ;
};



#endif // MODEL_H
