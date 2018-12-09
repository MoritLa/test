#ifndef CONNECTIONSCREEN_H
#define CONNECTIONSCREEN_H

#include <QWidget>
#include <QLineEdit>

#define NOTCONNECTED    0
#define CONNECTED       1
#define CONNECTING      2

typedef void (*ConnectionCallbackFP)(QString port) ;

namespace Ui {
class ConnectionScreen;
}

class ConnectionScreen : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionScreen(QWidget *parent = nullptr);
    void setCallbacks(ConnectionCallbackFP extMotor,
                      ConnectionCallbackFP extSensor,
                      ConnectionCallbackFP extECU) ;
    void changeButton(int device, int state) ;
    ~ConnectionScreen();
private slots:
    void motor_cb() ;
    void ECU_cb() ;
    void sensor_cb() ;
private:
    ConnectionCallbackFP extMotor_cb ;
    ConnectionCallbackFP extSensor_cb ;
    ConnectionCallbackFP extECU_cb ;

    Ui::ConnectionScreen *ui;
};

#endif // CONNECTIONSCREEN_H
