#ifndef CONNECTIONSCREEN_H
#define CONNECTIONSCREEN_H

#include <QWidget>
#include <QLineEdit>

#define MOTOR   0
#define SENSOR  1
#define MCU     2

#define CONNECTED       1
#define NOTCONNECTED    0

typedef void (*ConnectionCallbackFP)(QString port) ;

namespace Ui {
class ConnectionScreen;
}

class ConnectionScreen : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionScreen(QWidget *parent = nullptr);
    void setCallbacks(ConnectionCallbackFP extMotor, ConnectionCallbackFP extSensor, ConnectionCallbackFP extMCU) ;
    void changeButton(int device, int state) ;
    ~ConnectionScreen();
private slots:
    void motor_cb() ;
    void MCU_cb() ;
    void sensor_cb() ;
private:
    ConnectionCallbackFP extMotor_cb ;
    ConnectionCallbackFP extSensor_cb ;
    ConnectionCallbackFP extMCU_cb ;

    Ui::ConnectionScreen *ui;
};

#endif // CONNECTIONSCREEN_H
