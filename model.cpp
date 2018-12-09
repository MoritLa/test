#include "model.h"
#include <QObject>

#include "constants.h"

enum{LONGITUDINAL, LATERAL, UPWARDS} ;

Model::Model(ConnectionMonitor * outputEmitter, simulationScreen *outputScreen)
{
    OutputInterface = outputEmitter ;
    OutputWindow = outputScreen ;

    connect(&timer, SIGNAL(timeout()),this, SLOT(UpdateStep())) ;
    init() ;
}

void Model::init(void)
{
    //stop simulation if running
    simulate = 0 ;
    if(timer.isActive())
        timer.stop() ;

    //set initial values
    for(int i = 0; i<4;i++)
    {
        WheelSpeed[i] = 0;
        WheelTorque[i] = 0;
    }
    TrueSpeed = 0;
    TrueTorque = 0;
    netSpeed = 0;
    acceleration[0] = acceleration[1] = acceleration[2] = 0;

    StateOfCharge = INITIAL_CHARGE ;


    OutputWindow->UpdateScreen(WheelSpeed,
                               WheelTorque,
                               TrueSpeed,
                               TrueTorque,
                               StateOfCharge) ;

}

void Model::pause(void)
{
    simulate = !simulate;

    if (simulate)
        timer.start(1) ;
    else
        timer.stop() ;
}

// private slots
void Model::UpdateStep()
{
    /*
     * new Moment
     * new Speed, acceleration
     * new wheel_speed/motor speed
     * new charge
     * send to epucks
     * update infoscreen
     */
    if(simulate)
    {
        NewTorque() ;
        NewAcceleration() ;
        NewWheelSpeed() ;

        OutputWindow->UpdateScreen(WheelSpeed,WheelTorque, TrueSpeed, TrueTorque, StateOfCharge) ;
        OutputInterface->UpdateMotor(TrueSpeed,TrueTorque) ;
        OutputInterface->UpdateSensor(WheelSpeed, acceleration) ;
    }
}

void Model::setBreakPedal(int newBreakPedal)
{
    breakPedal = (double)newBreakPedal/MAX_BREAK_PEDAL ;
    OutputInterface->send_Pedals(breakPedal, acceleratorPedal) ;
}

void Model::setAccelerationPedal(int newAccelerationPedal)
{
    acceleratorPedal = (double)newAccelerationPedal/MAX_ACCELERATION_PEDAL ;
    OutputInterface->send_Pedals(breakPedal, acceleratorPedal) ;
//    TorqueSetpoint = acceleratorPedal*150 ;
}

void Model::setSteeringAngle(int newSteeringAngle)
{
    steeringAngle =  ((double) newSteeringAngle-MAX_STEERING_WHEEL)/MAX_STEERING_WHEEL*STEERING_FACTOR ;
    OutputInterface->send_steering(steeringAngle) ;
}

void Model::setSpeedSetpoint(int16_t speedSetpoint)
{
    SpeedSetpoint = ((double)speedSetpoint/MAX_VAL)*V_MAX ;
}

void Model::setTorqueSetpoint(int16_t torqueSetpoint)
{
    TorqueSetpoint = ((double)torqueSetpoint/MAX_VAL)*M_MAX_MOTOR ;
}

//private functions
void Model::NewTorque(void)
{
    if(StateOfCharge>0)
    {
        TrueTorque += TORQUE_STEP ;
        if(TrueTorque > TorqueSetpoint)
            TrueTorque = TorqueSetpoint ;
    }
    else
    {
        StateOfCharge = 0 ;
        TrueTorque = 0 ;
    }
}

void Model::NewAcceleration(void) //VSI
{
    double Traction = TrueTorque*((REDUCTION_FACTOR/EFFICIENCY)/(WHEEL_DIAMETER/2)) ;
    if (std::abs(Traction-breakPedal*BREAK_FACTOR) > MU * FN)
    {
        acceleration[LONGITUDINAL] = MU*FN/CAR_MASS ;
        if(Traction-breakPedal*BREAK_FACTOR < 0)
             acceleration[LONGITUDINAL] = -acceleration[LONGITUDINAL] ;
    }
    else
        acceleration[LONGITUDINAL] = (Traction-breakPedal*BREAK_FACTOR)/CAR_MASS ;
    acceleration[LONGITUDINAL] -= FRICTION; //breaking because of friction
    printf("%lf %lf %lf\n", Traction, breakPedal*BREAK_FACTOR,acceleration[LONGITUDINAL]) ;
    netSpeed += acceleration[LONGITUDINAL]*DELTA_T ;
    TrueSpeed = netSpeed/(PI*WHEEL_DIAMETER)*REDUCTION_FACTOR ;

    if (TrueSpeed <= 0)
    {
        acceleration[LONGITUDINAL] = 0;
       // TrueTorque = 0 ;
        netSpeed = 0 ;
        TrueSpeed = 0 ;
    }
    else if(TrueSpeed >= SpeedSetpoint)
    {
        acceleration[LONGITUDINAL] = 0;
        TrueTorque = 0;
        TrueSpeed = SpeedSetpoint ;
        netSpeed = TrueSpeed*(PI*WHEEL_DIAMETER)/REDUCTION_FACTOR;
    }

    OutputPower = TrueTorque*TrueSpeed/(60*2*PI) ;

    StateOfCharge = StateOfCharge - OutputPower*DELTA_T - LOSS; //LOSS are static losses

    acceleration[LATERAL] = netSpeed*netSpeed*tan(steeringAngle)/WHEEL_BASE ;
}

void Model::NewWheelSpeed(void)
{
    // front wheel -> formula
    // rear: if Traction>mu Fn acceleration
    //       else formula
    WheelSpeed[FR] = netSpeed/(PI*WHEEL_DIAMETER)*(1-TRACKWIDTH_FRONT/WHEEL_BASE*tan(steeringAngle)) ;
    WheelSpeed[FL] = netSpeed/(PI*WHEEL_DIAMETER)*(1+TRACKWIDTH_FRONT/WHEEL_BASE*tan(steeringAngle)) ;
    WheelSpeed[RR] = netSpeed/(PI*WHEEL_DIAMETER)*(1-TRACKWIDTH_REAR/WHEEL_BASE*tan(steeringAngle)) ;
    WheelSpeed[RL] = netSpeed/(PI*WHEEL_DIAMETER)*(1+TRACKWIDTH_REAR/WHEEL_BASE*tan(steeringAngle)) ;

    WheelTorque[FR] = 0 ;
    WheelTorque[FL] = 0 ;
    if (WheelSpeed[RR] <= 0)
        WheelTorque[RR] = 0 ;
    else
        WheelTorque[RR] = OutputPower/(WheelSpeed[RR]/(60*PI)); //half of the power goes to each wheel
    if (WheelSpeed[RL] <= 0)
        WheelTorque[RL] = 0 ;
    else
        WheelTorque[RL] = OutputPower/(WheelSpeed[RL]/(60*PI));
}

