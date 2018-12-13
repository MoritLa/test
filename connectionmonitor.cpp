#include "connectionmonitor.h"
#include "messages_header.h"
#include "constants.h"

#include <iostream>
#include <stdio.h>

using namespace std ;

//-------Public functions
ConnectionMonitor::ConnectionMonitor()
{
    connect(&timer, SIGNAL(timeout()),this, SLOT(ReadBuffer())) ;
}

void ConnectionMonitor::init(ConnectionScreen *extDisplay,
                             ReceiveCallbackFP speed_cb,
                             ReceiveCallbackFP torque_cb)
{
    Display = extDisplay ;
    extSpeed_cb = speed_cb ;
    extTorque_cb = torque_cb ;

    timer.start(10) ;
}

void ConnectionMonitor::ConnectMotor(QString port)
{
    uint8_t out[2] = {0x80,0x00} ;
    char in[4] ;
    Display->changeButton(MOTOR, CONNECTING) ;
    if(MotorConnected == NOTCONNECTED)
    {
        Motor.setBaudRate(MY_BAUD) ;
        Motor.setCommPort(port.toStdString()) ;
        if(Motor.connect())
        {
            Display->changeButton(MOTOR,NOTCONNECTED) ;
            MotorConnected = NOTCONNECTED ;

        }
        else
        {
            Motor.sendBuffer((char*) out, 2) ;
            Motor.receiveBuffer(in,4) ;
            cout<<"test 3"<< in[3]<<endl ;
            if(in[3] == MOTOR_TYPE)
            {
                Display->changeButton(MOTOR, CONNECTED) ;
                MotorConnected = CONNECTED ;
            }
            else
            {
                Motor.disconnect() ;
                Display->changeButton(MOTOR, NOTCONNECTED) ;
                MotorConnected = NOTCONNECTED ;
            }
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
    uint8_t out[2] = {0x80,0x00} ;
    char in[4] ;

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
            Sensor.sendBuffer((char*) out, 2) ;
            Sensor.receiveBuffer(in,4) ;
            if(in[3] == SENSOR_TYPE)
            {
                Display->changeButton(SENSOR, CONNECTED) ;
                SensorConnected = CONNECTED ;
            }
            else
            {
                Sensor.disconnect() ;
                Display->changeButton(SENSOR, NOTCONNECTED) ;
                SensorConnected = NOTCONNECTED ;
            }
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

void ConnectionMonitor::ConnectECU(QString port)
{
    uint8_t out[2] = {0x80,0x00} ;
    uint8_t in[4] ;
    int showIn[4] ;

    Display->changeButton(ECU, CONNECTING) ;
    if(EcuConnected == NOTCONNECTED)
    {
        Ecu.setBaudRate(MY_BAUD) ;
        Ecu.setCommPort(port.toStdString()) ;
        if(Ecu.connect())
        {
            Display->changeButton(ECU, NOTCONNECTED) ;
            EcuConnected = NOTCONNECTED ;
        }
        else
        {
            Ecu.sendBuffer((char*) out, 2) ;
            Ecu.receiveBuffer((char*) in,4) ;
            showIn[0] = in[0]; showIn[1] = in[1]; showIn[2] = in[2]; showIn[3] = in[3];
            if(in[3] == ECU_TYPE)
            {
                Display->changeButton(ECU, CONNECTED) ;
                EcuConnected = CONNECTED ;
            }
            else
            {
                Ecu.disconnect() ;
                Display->changeButton(ECU, NOTCONNECTED) ;
                EcuConnected = NOTCONNECTED ;
            }
        }
    }
    else
    {
        if(!Ecu.disconnect())
        {
            Display->changeButton(ECU, NOTCONNECTED) ;
            EcuConnected = NOTCONNECTED ;
        }
        else
        {
            Display->changeButton(ECU,CONNECTED) ;
            EcuConnected = CONNECTED ;
        }
    }
}

void ConnectionMonitor::StartReceiving(void)
{
    if(~timer.isActive())
        timer.start() ;
    connect(this, SIGNAL(timeout()),this, SLOT(ReadBuffer())) ;
}

void ConnectionMonitor::StopReceiving(void)
{
    timer.stop() ;
}

void ConnectionMonitor::UpdateMotor(double TrueSpeed, double TrueTorque)
{
    char output[MAX_UART_MESSAGE_LENGTH];
    uint16_t outdata ;
    //conversion not from float to uint8_t and to output format
    outdata = ((TrueSpeed*MAX_VAL)/V_MAX_MOTOR);
    output[0] = headers_S[MOTOR][TRUE_MOTOR_SPEED].id ; output[1] = headers_S[MOTOR][TRUE_MOTOR_SPEED].length ;
    output[2] = outdata; output[3] = outdata>>8;
    Motor.sendBuffer(output,2+headers_S[MOTOR][TRUE_MOTOR_SPEED].length) ;

    outdata = ((TrueTorque*MAX_VAL)/M_MAX_MOTOR);
    output[0] = headers_S[MOTOR][TRUE_MOTOR_TORQUE].id ; output[1] = headers_S[MOTOR][TRUE_MOTOR_TORQUE].length ;
    output[2] = outdata>>8; output[3] = outdata;
    Motor.sendBuffer(output,2+headers_S[MOTOR][TRUE_MOTOR_TORQUE].length) ;
}

void ConnectionMonitor::UpdateECU(void)
{

}

void ConnectionMonitor::UpdateSensor(double WheelSpeed[4], double Acceleration[3])
{
    char output[MAX_UART_MESSAGE_LENGTH+2];
    uint16_t outdata ;

    for(int i = 0; i<4;i++)
    {
        outdata = WheelSpeed[i]*MAX_VAL/V_MAX_WHEEL ;
        output[2+2*i] = outdata; output[3+2*i] = outdata>>8 ;
    }
    output[0] = headers_S[SENSOR][SENSOR].id ; output[1] = headers_S[SENSOR][SENSOR].length ;
    Sensor.sendBuffer(output,2+headers_S[SENSOR][TRUE_SPEED].length) ;

    for(int i = 0; i<3;i++)
    {
        outdata = Acceleration[i]*MAX_VAL/A_MAX ;
        output[2+2*i] = outdata; output[3+2*i] = outdata>>8 ;
    }
    output[0] = headers_S[SENSOR][ACCELERATION].id ; output[1] = headers_S[SENSOR][ACCELERATION].length ;
    Sensor.sendBuffer(output,2+headers_S[SENSOR][ACCELERATION].length) ;

}

void ConnectionMonitor::send_Pedals(double breakPedal, double accelerationPedal)
{
    char output[MAX_UART_MESSAGE_LENGTH];
    uint16_t outdata ;
    //conversion not from float to uint8_t and to output format
    outdata = breakPedal*MAX_VAL/MAX_BREAK_PEDAL;
    output[2] = outdata; output[3] = outdata>>8;
    outdata = accelerationPedal*MAX_VAL/MAX_ACCELERATION_PEDAL;
    output[4] = outdata; output[5] = outdata>>8;
    output[0] = headers_S[SENSOR][PEDALS].id ; output[1] = headers_S[SENSOR][PEDALS].length ;

    Sensor.sendBuffer(output,2+headers_S[SENSOR][PEDALS].length) ;

}

void ConnectionMonitor::send_steering(double steeringAngle)
{
    char output[MAX_UART_MESSAGE_LENGTH];
    uint16_t outdata ;
    //conversion not from float to uint8_t and to output format
    outdata = steeringAngle*MAX_VAL/STEERING_FACTOR ;
    output[2] = outdata; output[3] = outdata>>8;
    output[0] = headers_S[SENSOR][STEERING].id ; output[1] = headers_S[SENSOR][STEERING].length ;

    Sensor.sendBuffer(output,2+headers_S[SENSOR][STEERING].length) ;
}

//--------Private functions
void ConnectionMonitor::ReadBuffer(void)
{
    char id[2] ;
    int16_t data16 ;
    char length ;
    char data[64];
    if(~Motor.receiveBuffer(id, 2))
    {
        Motor.receiveBuffer(&length,1) ;
        Motor.receiveBuffer(data,length) ;

        if ((static_cast<int>(id[1])&0xFF) != ID_HIGH)
            return ;
        switch (static_cast<int>(id[0])&0xFF)
        {
        case SPEED_SETPOINT_ID :
            if(length = headers_R[MOTOR][SPEED_SETPOINT].length)
            {
                data16 = data[0]+(data[1]<<8) ;
                extSpeed_cb(data16);
            }
            break;
        case TORQUE_SETPOINT_ID:
            if(length = headers_R[MOTOR][TORQUE_SETPOINT].length)
            {
                data16 = data[0]+(data[1]<<8) ;
                extTorque_cb(data16);
            }
            break;
        default: break;
        }
    }
}
