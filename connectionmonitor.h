#ifndef CONNECTIONMONITOR_H
#define CONNECTIONMONITOR_H

#include "serialport/serialport.h"

#include <QString>

class ConnectionMonitor
{
private:
    SerialPort Motor, Sensor, MCU ;
public:
    ConnectionMonitor();

    int ConnectMotor(QString port) ;
    int ConnectSensor(QString port) ;
    int ConnectMCU(QString port) ;

};

#endif // CONNECTIONMONITOR_H
