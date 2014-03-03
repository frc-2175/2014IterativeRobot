#include "WPIlib.h"
#include "Shooter.h"

#define WINCH_DOWN	0.8
#define WINCH_UP	-0.7

Shooter::Shooter() {
	winchMotors = new Talon(3);

	winchEncoder = new Encoder(13,14,false,CounterBase::k4X);
	winchEncoder->SetDistancePerPulse(1.0);
	winchEncoder->SetMinRate(1.0);
	winchEncoder->SetSamplesToAverage(1);
	
	latchSolenoid = new Solenoid(3);
	tensionerSolenoid = new DoubleSolenoid(7,8);
	
	latchSwitch = new DigitalInput(4);
	sammySwitch = new DigitalInput(5);
	
	ballSensor = new AnalogChannel(2);
	
	currentShot = LongShot;
}

void Shooter::Init() {
	ChooseShot(LongShot);
	latchSolenoid->Set(false);
	
	winchEncoder->Start();
}

void Shooter::ReleaseLatch() {
	latchSolenoid->Set(true);
}

void Shooter::CloseLatch() {
	latchSolenoid->Set(false);
}

void Shooter::RunWinch(double value, bool sensorOverride) {
	if (value>0.0&&(!IsLatched()||sensorOverride) || value<0.0&&(!IsUnwound()||sensorOverride))
		winchMotors->Set(value);
	else
		winchMotors->Set(0.0);
}

void Shooter::WinchDown(bool sensorOverride) {
	RunWinch(WINCH_DOWN,sensorOverride);
}

void Shooter::WinchUp(bool sensorOverride) {
	RunWinch(WINCH_UP,sensorOverride);
}

void Shooter::ChooseShot(ShotChoice newShotChoice) {
	currentShot = newShotChoice;
	UpdateTensionSolenoid();
}

void Shooter::SwitchShot() {
	currentShot = (currentShot==LongShot)?ShortShot:LongShot;
	UpdateTensionSolenoid();
}

double Shooter::WinchOutput() {
	return 0.0;
}

bool Shooter::IsLatched() {
	return latchSwitch->Get();
}

bool Shooter::IsUnwound() {
	return sammySwitch->Get();
}

void Shooter::ResetEncoder() {
	winchEncoder->Reset();
}

double Shooter::WinchEncoderRate() {
	return winchEncoder->GetRate();
}

double Shooter::WinchEncoderDistance() {
	return winchEncoder->GetDistance();
}

double Shooter::WinchPosition() {
	return winchPosition;
}

bool Shooter::BallPossessed() {
	return ballPossessed;
}

double Shooter::BallDistance() {
	return ballDistance;
}

Shooter::ShotChoice Shooter::CurrentShot() {
	return currentShot;
}

void Shooter::UpdateTensionSolenoid() {
	tensionerSolenoid->Set((DoubleSolenoid::Value)currentShot);
}
