#include "infoscreen.h"
#include "cockpitscreen.h"
#include "connectionscreen.h"
#include "connectionmonitor.h"

#include <iostream>
#include <QApplication>
#include <QThread>
#include <QObject>

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
    EPuckMonitor->ConnectMotor(port) ;
}

void sensor_cb(QString port)
{
    EPuckMonitor->ConnectSensor(port) ;
}

void MCU_cb(QString port)
{
    EPuckMonitor->ConnectMCU(port) ;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InfoScreen = new infoScreen ;
    Cockpit = new CockpitScreen;
    Connection = new ConnectionScreen ;
    EPuckMonitor = new ConnectionMonitor ;

    Connection->setCallbacks(motor_cb, sensor_cb, MCU_cb) ;

    EPuckMonitor->setDisplay(Connection) ;

    InfoScreen->show() ;
    Cockpit->show() ;
    Connection->show() ;
    return a.exec();
}


