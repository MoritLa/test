#ifndef CONNECTIONMONITOR_H
#define CONNECTIONMONITOR_H

#include "serialport/serialport.h"
#include "connectionscreen.h"

#include <stdint.h>

#include <QString>
#include <QTimer>

typedef void (*ReceiveCallbackFP)(int16_t data) ;

class ConnectionMonitor: public QObject
{
    Q_OBJECT

private:
     QTimer timer ;
    ConnectionScreen * Display ;
    SerialPort Motor, Sensor, Ecu ;
    bool MotorConnected = NOTCONNECTED, SensorConnected =NOTCONNECTED, EcuConnected = NOTCONNECTED ;

    ReceiveCallbackFP extSpeed_cb ;
    ReceiveCallbackFP extTorque_cb ;
private slots:
    void ReadBuffer(void) ;
public:
    ConnectionMonitor();

    void init(ConnectionScreen *extDisplay,
              ReceiveCallbackFP speed_cb,
              ReceiveCallbackFP torque_cb) ;

    void ConnectMotor(QString port) ;
    void ConnectSensor(QString port) ;
    void ConnectECU(QString port) ;

    void StartReceiving(void) ;
    void StopReceiving(void) ;

    void UpdateMotor(double TrueSpeed, double TrueTorque) ;
    void UpdateECU(void) ;
    void UpdateSensor(double WheelSpeed[4], double Acceleration[3]) ;

    void send_Pedals(double breakPedal, double accelerationPedal) ;
    void send_steering(double steeringAngle) ;
};

#endif // CONNECTIONMONITOR_H
