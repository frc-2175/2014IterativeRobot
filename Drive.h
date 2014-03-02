enum ShiftState : bool { LowGear=true, HighGear=false };

class Drive {
public:
	Drive();
	void Init();
	void Shift(bool highGear);
	void ArcadeDrive(Joystick* stick1, Joystick *stick2);
	void Stop();
	
	ShiftState CurrentGear();
	double LeftSideOutput();
	double RightSideOutput();
	double ForwardOutput();
	double TurnOutput();
	double Heading();
	/*Encoder *GetLeftEncoder();
	Encoder *GetRightEncoder();*/
	void ResetEncoders();
	double LeftEncoderRate();
	double LeftEncoderDistance();
	double RightEncoderRate();
	double RightEncoderDistance();

private:
	Drive* drive;
	Solenoid* shifterSolenoid;
	Gyro* gyro;
	Encoder* leftEncoder;
	Encoder* rightEncoder;
	
	double leftSideOutput;
	double rightSideOutput;
	double forwardOutput;
	double turnOutput;
};
