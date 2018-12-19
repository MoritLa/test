#ifndef COCKPITSCREEN_H
#define COCKPITSCREEN_H

#include <QWidget>

typedef void (*CockpitButtonCallbackFP)(void) ;
typedef void (*CockpitValueCallbackFP)(int) ;

namespace Ui {
class CockpitScreen;
}

class CockpitScreen : public QWidget
{
    Q_OBJECT

public:
    explicit CockpitScreen(QWidget *parent = nullptr);
    ~CockpitScreen();
    void setCallbacks(CockpitButtonCallbackFP extStartStop,
                      CockpitButtonCallbackFP extRestart,
                      CockpitValueCallbackFP extDriveMode,
                      CockpitValueCallbackFP extBreak,
                      CockpitValueCallbackFP extBreakBalance,
                      CockpitValueCallbackFP extAccelerator,
                      CockpitValueCallbackFP extCruise,
                      CockpitButtonCallbackFP extDrive,
                      CockpitButtonCallbackFP extTS,
                      CockpitValueCallbackFP extUseEpuck,
                      CockpitValueCallbackFP extSteering,
                      CockpitButtonCallbackFP extQuit) ;
    void setStartButton(bool simulate);
    void setSteering(int angle) ;
private slots:
    void startStop(void);
    void restart(void) ;
    void driveMode_cb(int Mode) ;
    void break_cb(int BreakPedal) ;
    void breakBalance_cb(int BreakBalance) ;
    void accelerator_cb(int AcceleratorPedal) ;
    void cruise_cb(int MaxSpeed) ;
    void drive_cb(void) ;
    void TS_cb(void) ;
    void useEpuck(int use) ;
    void steering_cb(int SteeringAngle) ;
    void quit_cb(void) ;
private:
    CockpitButtonCallbackFP extStartStop_cb;
    CockpitButtonCallbackFP extRestart_cb ;
    CockpitValueCallbackFP extDriveMode_cb ;
    CockpitValueCallbackFP extBreak_cb ;
    CockpitValueCallbackFP extBreakBalance_cb ;
    CockpitValueCallbackFP extAccelerator_cb ;
    CockpitValueCallbackFP extCruise_cb ;
    CockpitButtonCallbackFP extDrive_cb ;
    CockpitButtonCallbackFP extTS_cb ;
    CockpitValueCallbackFP extUseEpuck_cb ;
    CockpitValueCallbackFP extSteering_cb ;
    CockpitButtonCallbackFP extQuit_cb ;

    Ui::CockpitScreen *ui;
    bool useSlider = 1;
};

#endif // COCKPITSCREEN_H
