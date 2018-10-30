#include "connectionmonitor.h"

#define MY_BAUD    115200

ConnectionMonitor::ConnectionMonitor()
{

}

int ConnectionMonitor::ConnectMotor(QString port)
{
    Motor.setBaudRate(MY_BAUD) ;
    Motor.setCommPort(port.toStdString()) ;
    return Motor.connect() ;
}

int ConnectionMonitor::ConnectSensor(QString port)
{
    Sensor.setBaudRate(MY_BAUD) ;
    Sensor.setCommPort(port.toStdString()) ;
    return Sensor.connect() ;
}

int ConnectionMonitor::ConnectMCU(QString port)
{
    MCU.setBaudRate(MY_BAUD) ;
    MCU.setCommPort(port.toStdString()) ;
    return MCU.connect() ;
}
