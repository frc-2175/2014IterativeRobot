#include "WPILib.h"
#include "Drive.h"

#define D_PER_PULSE	1.0
#define MIN_RATE	1.0
#define AVG_SAMPLES	1

Drive::Drive() {
	drive = new RobotDrive(1,2);
	drive->SetExpiration(0.1);
	drive->SetSafetyEnabled(true);
	
	leftEncoder = new Encoder(1,2,false,CounterBase::k4X);
	rightEncoder = new Encoder(3,4,true,CounterBase::k4X);
	leftEncoder->SetDistancePerPulse(D_PER_PULSE);
	leftEncoder->SetMinRate(MIN_RATE);
	leftEncoder->SetSamplesToAverage(AVG_SAMPLES);
	rightEncoder->SetDistancePerPulse(D_PER_PULSE);
	rightEncoder->SetMinRate(MIN_RATE);
	rightEncoder->SetSamplesToAverage(AVG_SAMPLES);
	
	shifterSolenoid = new DoubleSolenoid(1,2);
	
	gyro = new Gyro(1);
}

void Drive::Init() {
	leftEncoder->Start();
	rightEncoder->Start();
	
	Shift(Drive::LowGear);
}

void Drive::DriveUpdate(Joystick *stick1, Joystick *stick2) {
	drive->ArcadeDrive(stick1->GetY(),stick2->GetX(),false);
	Shift(stick2->GetRawButton(1)?HighGear:LowGear);
}

void Drive::Shift(Gear newGear) {
	shifterSolenoid->Set((DoubleSolenoid::Value)gear);
	gear = newGear;
}

void Drive::Stop() {
	drive->ArcadeDrive(0.0,0.0);
}

Drive::Gear Drive::CurrentGear() {
	return gear;
}

double Drive::LeftSideOutput() {
	 return leftSideOutput;
}

double Drive::RightSideOutput() {
	 return rightSideOutput;
}

double Drive::ForwardOutput() {
	return forwardOutput;
}

double Drive::TurnOutput() {
	return turnOutput;
}

double Drive::Heading() {
	return gyro->GetAngle();
}

void Drive::ResetEncoders() {
	leftEncoder->Reset();
	rightEncoder->Reset();
}

double Drive::LeftEncoderDistance() {
	return leftEncoder->GetDistance();
}

double Drive::LeftEncoderRate() {
	return leftEncoder->GetRate();
}

double Drive::RightEncoderDistance() {
	return rightEncoder->GetDistance();
}

double Drive::RightEncoderRate() {
	return rightEncoder->GetRate();
}
