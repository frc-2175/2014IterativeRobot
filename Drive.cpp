#include "WPIlib.h"

Drive::Drive() {
	
}

Drive::Init() {
	
}

Drive::ArcadeDrive(Joystick *stick1, Joystick *stick2) {
	drive.ArcadeDrive(stick1->GetY(),stick2->GetX(),false);
}

Drive::Shift(ShiftState gear) {
	
}
