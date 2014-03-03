class Shooter {
public:
	typedef enum { LongShot=1, ShortShot=2 } ShotChoice;
	Shooter();
	void Init();
	void ReleaseLatch();
	void CloseLatch();
	void RunWinch(double value, bool sensorOverride);
	void WinchDown(bool sensorOverride);
	void WinchUp(bool sensorOverride);
	void ChooseShot(ShotChoice newShotChoice);
	void SwitchShot();
	
	double WinchOutput();
	bool IsLatched();
	bool IsUnwound();
	void ResetEncoder();
	double WinchEncoderRate();
	double WinchEncoderDistance();
	double WinchPosition();
	bool BallPossessed();
	double BallDistance();
	ShotChoice CurrentShot();

private:
	void UpdateTensionSolenoid();
	
	Solenoid* latchSolenoid;
	DoubleSolenoid* tensionerSolenoid;
	Talon* winchMotors;
	Encoder* winchEncoder;
	DigitalInput* latchSwitch;
	DigitalInput* sammySwitch;
	AnalogChannel* ballSensor;
	
	double winchPosition;
	double ballDistance;
	bool ballPossessed;
	ShotChoice currentShot;
};
