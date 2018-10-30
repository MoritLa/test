#include "infoscreen.h"
#include "cockpitscreen.h"
#include "connectionscreen.h"
#include "connectionmonitor.h"

#include <iostream>
#include <QApplication>
namespace
{
    static infoScreen *InfoScreen ;
    static CockpitScreen *Cockpit ;
    static ConnectionScreen *Connection ;

    static ConnectionMonitor *EPuckMonitor ;
}
// callback functions
void motor_cb(QString port)
{
    if(EPuckMonitor->ConnectMotor(port))
        Connection->changeButton(MOTOR, NOTCONNECTED) ;
    else
        Connection->changeButton(MOTOR, CONNECTED) ;
}

void sensor_cb(QString port)
{
    if(EPuckMonitor->ConnectSensor(port))
        Connection->changeButton(MOTOR, NOTCONNECTED) ;
    else
        Connection->changeButton(MOTOR, CONNECTED) ;
}

void MCU_cb(QString port)
{
    if(EPuckMonitor->ConnectMCU(port))
        Connection->changeButton(MOTOR, NOTCONNECTED) ;
    else
        Connection->changeButton(MOTOR, CONNECTED) ;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InfoScreen = new infoScreen ;
    Cockpit = new CockpitScreen;
    Connection = new ConnectionScreen ;

    Connection->setCallbacks(motor_cb, sensor_cb, MCU_cb) ;


    InfoScreen->show() ;
    Cockpit->show() ;
    Connection->show() ;

    return a.exec();
}


