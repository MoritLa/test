#ifndef INFOSCREEN_H
#define INFOSCREEN_H

#include <QWidget>

enum{FL,FR,RR,RL} ;

namespace Ui {
class simulationScreen;
}

class simulationScreen : public QWidget
{
    Q_OBJECT

public:
    explicit simulationScreen(QWidget *parent = nullptr);
    ~simulationScreen();

    void UpdateScreen(double WheelSpeed[4],
                      double WheelTorque[4],
                      double MotorSpeed,
                      double MotorTroque,
                      double StateOfCharge);
    void setSteeringAngle(double angle) ;
private:
    Ui::simulationScreen *ui;
};

#endif // INFOSCREEN_H
