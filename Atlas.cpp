#include "WPILib.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The IterativeRobot class is the base of a robot application that will automatically call your
 * Periodic methods for each packet based on the mode.
 */ 
class Atlas : public IterativeRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick stick1; // drive joystick 1 (left)
	Joystick stick2; // drive joystick 2 (right)
	Joystick stick3; // weapons
	/*Drive drive;
	Shooter shooter;
	RollerBar rollerBar;
	Compressor compressor;
	Sensors sensors;*/

public:
	Atlas():
		myRobot(1, 2),	// these must be initialized in the same order
		stick1(1),		// as they are declared above.
		stick2(2),
		stick3(3)
	{
		myRobot.SetExpiration(0.1);
		this->SetPeriod(0); 	//Set update period to sync with robot control packets (20ms nominal)
		
	}
	
/**
 * Robot-wide initialization code should go here.
 * 
 * Use this method for default Robot-wide initialization which will
 * be called when the robot is first powered on.  It will be called exactly 1 time.
 * This should parallel Begin.vi in default LabView framework
 */
void Atlas::RobotInit() {
	
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
	
}

/**
 * Periodic code for teleop mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in teleop mode.
 */
void Atlas::TeleopPeriodic() {
	myRobot.ArcadeDrive(stick1); // drive with arcade style 
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

