#ifndef CONNECTIONMONITOR_H
#define CONNECTIONMONITOR_H

#include "serialport/serialport.h"
#include "connectionscreen.h"

#include <QString>

class ConnectionMonitor
{
private:
    ConnectionScreen * Display ;
    SerialPort Motor, Sensor, Mcu ;
    bool MotorConnected = NOTCONNECTED, SensorConnected =NOTCONNECTED, McuConnected = NOTCONNECTED ;
public:
    ConnectionMonitor();

    void setDisplay(ConnectionScreen *extDisplay) ;

    void ConnectMotor(QString port) ;
    void ConnectSensor(QString port) ;
    void ConnectMCU(QString port) ;

};

#endif // CONNECTIONMONITOR_H
