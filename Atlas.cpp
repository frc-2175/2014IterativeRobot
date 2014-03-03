#include "WPILib.h"
#include "Drive.h"
#include "Shooter.h"
//#include "RollerBar.h"

#define D_PER_PULSE	1.0
#define MIN_RATE	1.0
#define AVG_SAMPLES	1

#define WINCH_DOWN	0.8
#define WINCH_UP	-0.7

#define ROLLER_IN	1.0
#define ROLLER_OUT	-1.0

/**
 * This is a demo program showing the use of the RobotBase class.
 * The IterativeRobot class is the base of a robot application that will automatically call your
 * Periodic methods for each packet based on the mode.
 */ 
class Atlas : public IterativeRobot
{
	Joystick leftStick; // drive joystick 1 (left)
	Joystick rightStick; // drive joystick 2 (right)
	Joystick weapons; // weapons
	Drive drive;
	Shooter shooter;
	//RollerBar rollerBar;
	Compressor compressor;
	
	RobotDrive drivetrain;
	Talon winch;
	Talon rollerBar;
	
	DoubleSolenoid shifters;
	DoubleSolenoid arm;
	Solenoid latch;
	DoubleSolenoid tensioner;
	Solenoid catcher;
	
	Encoder leftEncoder;
	Encoder rightEncoder;
	Encoder winchEncoder;
	
	Gyro gyro;
	AnalogChannel ballSensor;
	
	DigitalInput armSwitch1;
	DigitalInput armSwitch2;
	DigitalInput latchSwitch;
	DigitalInput sammySwitch;
	
	typedef enum { ArmIn=DoubleSolenoid::kReverse, ArmOut=DoubleSolenoid::kForward } ArmPosition;
	typedef enum { ShortShot=DoubleSolenoid::kReverse, LongShot=DoubleSolenoid::kForward } ShotChoice;
	typedef enum { LowGear=DoubleSolenoid::kReverse, HighGear=DoubleSolenoid::kForward } Gear;
	ArmPosition armPosition;
	ShotChoice shotChoice;
	Gear gear;
	bool latchState;
	bool catcherState;
	
	typedef enum { Wait, Winch, Unwinch } ShootState;
	ShootState shootState;
	bool shotyet;
	double shot_time;
	
public:
	Atlas():
		//myRobot(1, 2),	// these must be initialized in the same order
		leftStick(1),		// as they are declared above.
		rightStick(2),
		weapons(3),
		/*drive(),
		shooter(),*/
		//rollerBar(),
		compressor(1,7,1,3),
		drivetrain(1,2),
		winch(3),
		rollerBar(4),
		shifters(1,2),
		arm(3,4),
		latch(5),
		tensioner(6,7),
		catcher(8),
		leftEncoder(1,2,false,CounterBase::k4X),
		rightEncoder(3,4,true,CounterBase::k4X),
		winchEncoder(13,14,false,CounterBase::k4X),
		gyro(1),
		ballSensor(2),
		armSwitch1(10),
		armSwitch2(11),
		latchSwitch(5),
		sammySwitch(8)
	{
		this->SetPeriod(0); 	//Set update period to sync with robot control packets (20ms nominal)
		
		drivetrain.SetExpiration(0.1);
		drivetrain.SetSafetyEnabled(true);
		
		leftEncoder.SetDistancePerPulse(D_PER_PULSE);
		leftEncoder.SetMinRate(MIN_RATE);
		leftEncoder.SetSamplesToAverage(AVG_SAMPLES);
		rightEncoder.SetDistancePerPulse(D_PER_PULSE);
		rightEncoder.SetMinRate(MIN_RATE);
		rightEncoder.SetSamplesToAverage(AVG_SAMPLES);

		winchEncoder.SetDistancePerPulse(1.0);
		winchEncoder.SetMinRate(1.0);
		winchEncoder.SetSamplesToAverage(1);
		
		armPosition = ArmIn;
		shotChoice = LongShot;
		gear = LowGear;
		latchState = false;
		catcherState = false;
	}
	
/**
 * Robot-wide initialization code should go here.
 * 
 * Use this method for default Robot-wide initialization which will
 * be called when the robot is first powered on.  It will be called exactly 1 time.
 * This should parallel Begin.vi in default LabView framework
 */
void Atlas::RobotInit() {
	/*drive.Init();
	shooter.Init();*/
	//rollerBar.Init();
			
	shifters.Set((DoubleSolenoid::Value)gear);
	arm.Set((DoubleSolenoid::Value)armPosition);
	tensioner.Set((DoubleSolenoid::Value)shotChoice);
	latch.Set(latchState);
	catcher.Set(catcherState);
	
	leftEncoder.Start();
	rightEncoder.Start();
	winchEncoder.Start();
	
	compressor.Start();
}

/**
 * Initialization code for disabled mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters disabled mode. 
 */
void Atlas::DisabledInit() {
	
}

/**
 * Periodic code for disabled mode should go here.
 * 
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in disabled mode.
 */
void Atlas::DisabledPeriodic() {
	
}

/**
 * Initialization code for autonomous mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters autonomous mode.
 */
void Atlas::AutonomousInit() {
	
}

/**
 * Periodic code for autonomous mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in autonomous mode.
 */
void Atlas::AutonomousPeriodic() {
	
}

/**
 * Initialization code for teleop mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters teleop mode.
 */
void Atlas::TeleopInit() {
	/*drive.DriveUpdate(&leftStick,&rightStick);
	
	if (weapons.GetRawButton(9))
		shooter.WinchDown(weapons.GetRawButton(6));
	else if(weapons.GetRawButton(10))
		shooter.WinchUp(weapons.GetRawButton(6));
	else
		shooter.RunWinch(0.0,false);
	if (weapons.GetRawButton(11)&&weapons.GetRawButton(12))
		shooter.ReleaseLatch();
	else
		shooter.CloseLatch();
	if (leftStick.GetRawButton(1))
		shooter.SwitchShot();*/
	
	/*if (weapons.GetRawButton(1))
		rollerBar.MoveArmIn();
	else if (weapons.GetRawButton(4))
		rollerBar.MoveArmOut();
	if (weapons.GetRawButton(5))
		rollerBar.Suck(false);
	else if (weapons.GetRawButton(7))
		rollerBar.Suck(true);
	else
		rollerBar.StopRoller();*/
	
	
	/* Drive code */
	drivetrain.ArcadeDrive(leftStick.GetY(),rightStick.GetX(),false);
	shifters.Set(rightStick.GetRawButton(1)?DoubleSolenoid::kForward:DoubleSolenoid::kReverse);
	
	/* Shooter code */
	// if we want a shoot sequence, just put a state machine here with switch statement
	// no need for commands...
	
	bool down = weapons.GetRawButton(9);
	bool up = weapons.GetRawButton(10);
	bool sensorOverride = weapons.GetRawButton(6);
	bool winchDown = latchSwitch.Get();
	bool winchUp = sammySwitch.Get();
	if (down && !up && (!winchDown || sensorOverride))
		winch.Set(WINCH_DOWN);
	else if (up && !down && (!winchUp || sensorOverride))
		winch.Set(WINCH_UP);
	else
		winch.Set(0.0);
		
	latchState = weapons.GetRawButton(11)&&weapons.GetRawButton(12);
	latch.Set(latchState);
	
	if (leftStick.GetRawButton(1)) // toggle option
		shotChoice = (shotChoice==LongShot)?ShortShot:LongShot;
	//shotChoice = stick1.GetRawButton(1)?LongShot:ShortShot; // momentary option
	tensioner.Set((DoubleSolenoid::Value)shotChoice);
	
	/* Roller Bar code */
	if (weapons.GetRawButton(5))
		rollerBar.Set(ROLLER_OUT);
	else if(weapons.GetRawButton(7))
		rollerBar.Set(ROLLER_IN);
	else
		rollerBar.Set(0);
	if (weapons.GetRawButton(1))
		armPosition = ArmIn;
	else if (weapons.GetRawButton(4))
		armPosition = ArmOut;
	arm.Set((DoubleSolenoid::Value)armPosition);
}

/**
 * Periodic code for teleop mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in teleop mode.
 */
void Atlas::TeleopPeriodic() {
	//drive.DriveUpdate(&stick1,&stick2); // drive with arcade style 
}

/**
 * Initialization code for test mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters test mode.
 */
void Atlas::TestInit() {
	
}

/**
 * Periodic code for test mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in test mode.
 */
void Atlas::TestPeriodic() {
	
}

};

START_ROBOT_CLASS(Atlas);

