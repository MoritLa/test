#include "cockpitscreen.h"
#include "ui_cockpitscreen.h"

CockpitScreen::CockpitScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CockpitScreen)
{
    ui->setupUi(this);
}

CockpitScreen::~CockpitScreen()
{
    delete ui;
}
//public functions
void CockpitScreen::setCallbacks(CockpitButtonCallbackFP extStartStop,
                                 CockpitButtonCallbackFP extRestart,
                                 CockpitValueCallbackFP extDriveMode,
                                 CockpitValueCallbackFP extBreak,
                                 CockpitValueCallbackFP extBreakBalance,
                                 CockpitValueCallbackFP extAccelerator,
                                 CockpitValueCallbackFP extCruise,
                                 CockpitButtonCallbackFP extDrive,
                                 CockpitButtonCallbackFP extTS,
                                 CockpitValueCallbackFP extUseEpuck,
                                 CockpitValueCallbackFP extSteering)
{
    extStartStop_cb =extStartStop;
    extRestart_cb = extRestart;
    extDriveMode_cb = extDriveMode ;
    extBreak_cb = extBreak ;
    extBreakBalance_cb = extBreakBalance ;
    extAccelerator_cb = extAccelerator ;
    extCruise_cb = extCruise ;
    extDrive_cb = extDrive ;
    extTS_cb = extTS ;
    extUseEpuck_cb = extUseEpuck ;
    extSteering_cb = extSteering ;
}

//private slots
void CockpitScreen::startStop(void)
{
    extStartStop_cb() ;
}
void CockpitScreen::restart(void)
{
    extRestart_cb() ;
}
void CockpitScreen::driveMode_cb(int Mode)
{
    extDriveMode_cb(Mode) ;
}
void CockpitScreen::break_cb(int BreakPedal)
{
    extBreak_cb(BreakPedal) ;
}
void CockpitScreen::breakBalance_cb(int BreakBalance)
{
    extBreakBalance_cb(BreakBalance) ;
}
void CockpitScreen::accelerator_cb(int AcceleratorPedal)
{
    extAccelerator_cb(AcceleratorPedal) ;
}
void CockpitScreen::cruise_cb(int MaxSpeed)
{
    extCruise_cb(MaxSpeed) ;
}
void CockpitScreen::drive_cb(void)
{
    extDrive_cb() ;
}
void CockpitScreen::TS_cb(void)
{
    extTS_cb() ;
}
void CockpitScreen::useEpuck(int use)
{
    extUseEpuck_cb(use) ;
}
void CockpitScreen::steering_cb(int SteeringAngle)
{
    extSteering_cb(SteeringAngle) ;
}
