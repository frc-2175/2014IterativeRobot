class Shooter {
public:
	Shooter();
	void Init();
	void ReleaseLatch();
	void RunWinch(float value);
	
	double WinchOutput();
	bool IsLatched();
	bool IsUnwouned();
	void ResetEncoder();
	double WinchEncoderRate();
	double WinchEncoderDistance();
	double WinchPosition();
	bool BallPossessed();
	double BallDistace();

private:
	Solenoid* latchSolenoid;
	Solenoid* tensionerSolenoid;
	Talon* winchMotors;
	Encoder* winchEncoder;
	DigitalInput* latchSwitch;
	DigitalInput* sammySwitch;
	AnalogChannel* ballSensor;
	
	double winchPosition;
	double ballDistance;
	bool ballPossessed;
};
