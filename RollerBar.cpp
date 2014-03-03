#include "WPIlib.h"
#include "RollerBar.h"

RollerBar::RollerBar() {
	armSolenoid = new DoubleSolenoid(3,4);
	armSensor1 = new DigitalInput(10);
	armSensor2 = new DigitalInput(11);
	rollerMotors = new Talon(4);
	
	armPosition = In;
}

void RollerBar::Init() {
	MoveArmIn();
}

void RollerBar::MoveArmIn() {
	armPosition = In;
	UpdateArmSolenoid();
}

void RollerBar::MoveArmOut() {
	armPosition = Out;
	UpdateArmSolenoid();
}

void RollerBar::MoveArm(ArmPosition position) {
	armPosition = position;
	UpdateArmSolenoid();
}

void RollerBar::UpdateArmSolenoid() {
	armSolenoid->Set((DoubleSolenoid::Value)armPosition);
}

bool RollerBar::IsArmOut() {
	return armSensor1->Get()||armSensor2->Get();
}

RollerBar::ArmPosition RollerBar::GetArmPosition() {
	return armPosition;
}

void RollerBar::Suck(bool suckIn) {
	rollerMotors->Set(suckIn?1.0:-0.5);
}

void RollerBar::RunRoller(double value) {
	rollerMotors->Set(value);
}

void RollerBar::StopRoller() {
	rollerMotors->Set(0.0);
}
