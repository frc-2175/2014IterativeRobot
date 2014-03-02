#include "WPIlib.h"
#include "Drive.h"


Drive::Drive() {
	drive->SetExpiration(0.1);
}

void Drive::Init() {
	
}

void Drive::DriveUpdate(Joystick *stick1, Joystick *stick2) {
	drive->ArcadeDrive(stick1->GetY(),stick2->GetX(),false);
}

void Drive::Shift(bool gear) {
	
}
