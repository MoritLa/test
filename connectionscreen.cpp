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
        if (state == CONNECTED)
            ui->ConnectMotor->setText("Disconnect") ;
        else
            ui->ConnectMotor->setText("Connect") ;
        break ;
    case SENSOR :
        if (state == CONNECTED)
            ui->ConnectMotor->setText("Disconnect") ;
        else
            ui->ConnectMotor->setText("Connect") ;
        break ;
    case MCU    :
        if (state == CONNECTED)
            ui->ConnectMotor->setText("Disconnect") ;
        else
            ui->ConnectMotor->setText("Connect") ;
        break ;
    default     : break ;
    }
    ui->ConnectMotor->setText("Ho") ;
}
