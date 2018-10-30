#include "connectionmonitor.h"

#define MY_BAUD    57600 //115200

//-------Public functions
ConnectionMonitor::ConnectionMonitor()
{

}

void ConnectionMonitor::setDisplay(ConnectionScreen *extDisplay)
{
    Display = extDisplay ;
}

void ConnectionMonitor::ConnectMotor(QString port)
{
    Display->changeButton(MOTOR, CONNECTING) ;
    if(MotorConnected == NOTCONNECTED)
    {
        Motor.setBaudRate(MY_BAUD) ;
        Motor.setCommPort(port.toStdString()) ;
        if(Motor.connect())
        {
            Display->changeButton(MOTOR, NOTCONNECTED) ;
            MotorConnected = NOTCONNECTED ;
        }
        else
        {
            Display->changeButton(MOTOR,CONNECTED) ;
            MotorConnected = CONNECTED ;
        }
    }
    else
    {
        if(!Motor.disconnect())
        {
            Display->changeButton(MOTOR, NOTCONNECTED) ;
            MotorConnected = NOTCONNECTED ;
        }
        else
        {
            Display->changeButton(MOTOR,CONNECTED) ;
            MotorConnected = CONNECTED ;
        }
    }
}

void ConnectionMonitor::ConnectSensor(QString port)
{
    Display->changeButton(SENSOR, CONNECTING) ;
    if (SensorConnected == NOTCONNECTED)
    {
        Sensor.setBaudRate(MY_BAUD) ;
        Sensor.setCommPort(port.toStdString()) ;
        if(Sensor.connect())
        {
            Display->changeButton(SENSOR, NOTCONNECTED) ;
            SensorConnected = NOTCONNECTED ;
        }
        else
        {
            Display->changeButton(SENSOR,CONNECTED) ;
            SensorConnected = CONNECTED ;
        }
    }
    else
    {
        if(!Sensor.disconnect())
        {
            Display->changeButton(SENSOR, NOTCONNECTED) ;
            SensorConnected = NOTCONNECTED ;
        }
        else
        {
            Display->changeButton(SENSOR,CONNECTED) ;
            SensorConnected = CONNECTED ;
        }
    }
}

void ConnectionMonitor::ConnectMCU(QString port)
{
    Display->changeButton(MCU, CONNECTING) ;
    if(McuConnected == NOTCONNECTED)
    {
        Mcu.setBaudRate(MY_BAUD) ;
        Mcu.setCommPort(port.toStdString()) ;
        if(Mcu.connect())
        {
            Display->changeButton(MCU, NOTCONNECTED) ;
            McuConnected = NOTCONNECTED ;
        }
        else
        {
            Display->changeButton(MCU,CONNECTED) ;
            McuConnected = CONNECTED ;
        }
    }
    else
    {
        if(!Mcu.disconnect())
        {
            Display->changeButton(MCU, NOTCONNECTED) ;
            McuConnected = NOTCONNECTED ;
        }
        else
        {
            Display->changeButton(MCU,CONNECTED) ;
            McuConnected = CONNECTED ;
        }
    }
}

//--------Private functions

