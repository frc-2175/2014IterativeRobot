//enum RollerState : bool { In=true, Out=false };
//enum ArmPosition : bool { In=true, Out=false };

class RollerBar {
public:
	RollerBar();
	void Init();
	void Suck(bool direction);
	void MoveArm(bool position);
	void Stop();
	
	bool ArmOutput();
	bool IsArmOut();
	double RollerSpeed();

private:
	Solenoid* armSolenoid;
	DigitalInput* armSensor1;
	DigitalInput* armSensor2;
	Talon* rollerMotors;
	
	double rollerSpeed;
	bool armOutput;
};
