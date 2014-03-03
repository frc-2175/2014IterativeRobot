class Drive {
public:
	typedef enum { HighGear=DoubleSolenoid::kForward, LowGear=DoubleSolenoid::kReverse } Gear;// : bool ;
	
	Drive();
	void Init();
	void Shift(Gear newGear);
	void DriveUpdate(Joystick* stick1, Joystick *stick2);
	void Stop();
	
	Gear CurrentGear();
	double LeftSideOutput();
	double RightSideOutput();
	double ForwardOutput();
	double TurnOutput();
	double Heading();
	void ResetEncoders();
	double LeftEncoderRate();
	double LeftEncoderDistance();
	double RightEncoderRate();
	double RightEncoderDistance();

private:
	RobotDrive* drive;
	DoubleSolenoid* shifterSolenoid;
	Gyro* gyro;
	Encoder* leftEncoder;
	Encoder* rightEncoder;
	
	double leftSideOutput;
	double rightSideOutput;
	double forwardOutput;
	double turnOutput;
	double heading;
	double distance;
	Gear gear;
};
