//enum ShiftState : bool { LowGear=true, HighGear=false };

class Drive {
public:
	Drive();
	void Init();
	void Shift(bool highGear);
	void DriveUpdate(Joystick* stick1, Joystick *stick2);
	void Stop();
	
	bool CurrentGear();
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
	Solenoid* shifterSolenoid;
	Gyro* gyro;
	Encoder* leftEncoder;
	Encoder* rightEncoder;
	
	double leftSideOutput;
	double rightSideOutput;
	double forwardOutput;
	double turnOutput;
	double heading;
	double distance;
	bool gear;
};
