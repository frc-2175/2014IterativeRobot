class RollerBar {
public:
	typedef enum { In=DoubleSolenoid::kReverse, Out=DoubleSolenoid::kForward } ArmPosition;
	
	RollerBar();
	void Init();
	void Suck(bool suckIn);
	void RunRoller(double value);
	void StopRoller();
	void MoveArmOut();
	void MoveArmIn();
	void MoveArm(ArmPosition position);
	
	bool IsArmOut();
	ArmPosition GetArmPosition();
	
private:
	void UpdateArmSolenoid();

	DoubleSolenoid* armSolenoid;
	DigitalInput* armSensor1;
	DigitalInput* armSensor2;
	Talon* rollerMotors;

	ArmPosition armPosition;
};
