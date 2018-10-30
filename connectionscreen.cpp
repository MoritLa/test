#include "connectionscreen.h"
#include "ui_connectionscreen.h"

#include <iostream>

ConnectionScreen::ConnectionScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionScreen)
{
    ui->setupUi(this);

}

ConnectionScreen::~ConnectionScreen()
{
    delete ui;
}
 // Callback functions for text entered
void ConnectionScreen::motor_cb(void)
{
    extMotor_cb(this->ui->MotorPort->text()) ;
}
void ConnectionScreen::sensor_cb(void)
{
    extSensor_cb(this->ui->SensorPort->text()) ;
}
void ConnectionScreen::MCU_cb(void)
{
    extMCU_cb(this->ui->MCUPort->text()) ;
}

// initialise callback Functions
void ConnectionScreen::setCallbacks(ConnectionCallbackFP extMotor, ConnectionCallbackFP extSensor, ConnectionCallbackFP extMCU)
{
    extMotor_cb = extMotor ;
    extSensor_cb = extSensor ;
    extMCU_cb = extMCU ;
}

void ConnectionScreen::changeButton(int device, int state)
{
    switch (device)
    {
    case MOTOR  :
        switch (state)
        {
        case CONNECTED:     ui->ConnectMotor->setText("Disconnect") ;   break ;
        case CONNECTING:    ui->ConnectMotor->setText("...") ;          break ;
        case NOTCONNECTED:  ui->ConnectMotor->setText("Connect") ;      break ;
        }break ;
    case SENSOR :
        switch (state)
        {
        case CONNECTED:     ui->ConnectSensor->setText("Disconnect") ;   break ;
        case CONNECTING:    ui->ConnectSensor->setText("...") ;          break ;
        case NOTCONNECTED:  ui->ConnectSensor->setText("Connect") ;      break ;
        }break ;
    case MCU    :
        switch (state)
        {
        case CONNECTED:     ui->ConnectMcu->setText("Disconnect") ;   break ;
        case CONNECTING:    ui->ConnectMcu->setText("...") ;          break ;
        case NOTCONNECTED:  ui->ConnectMcu->setText("Connect") ;      break ;
        }break ;
    default     : break ;
    }
}
