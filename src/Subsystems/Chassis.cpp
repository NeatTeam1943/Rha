#include "Chassis.h"
#include "../RobotMap.h"
#include "../Commands/Chassis/DriveJoystick.h"

Chassis::Chassis() :
		Subsystem("Chassis") {
	this->deino = new RobotDrive(new CANTalon(CHASSIS_LEFTA),
			new CANTalon(CHASSIS_LEFTB), new CANTalon(CHASSIS_RIGHTA),
			new CANTalon(CHASSIS_RIGHTB));
	//this->deino->SetInvertedMotor(RobotDrive::MotorType::kFrontLeftMotor,true);
	//this->deino->SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor,true);
	//this->deino->SetInvertedMotor(RobotDrive::MotorType::kFrontRightMotor,true);
	//this->deino->SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor,true);
	this->deino->SetSafetyEnabled(false);
}

void Chassis::InitDefaultCommand() {
	SetDefaultCommand(new DriveJoystick(CommandBase::oi->GetStick()));
	//SetDefaultCommand(new TankDrive(CommandBase::oi->GetStick()));
}

void Chassis::Drive(float mag, float rot) {
	this->deino->ArcadeDrive(mag, rot, false);
}

void Chassis::DriveAccurate(float mag, float rot) {
	this->deino->ArcadeDrive(mag, rot, true);
}

void Chassis::Drive(Joystick *stick) {
	float x = 0, y = 0;
	if (stick->GetRawAxis(1) > 0.1 || stick->GetRawAxis(1) < -0.1)
		y = -stick->GetRawAxis(1);
	if (stick->GetRawAxis(0) > 0.1 || stick->GetRawAxis(0) < -0.1)
		x = -stick->GetRawAxis(0);
	this->deino->ArcadeDrive(y, x, stick->GetRawButton(8));

}//Right Stick

void Chassis::DriveTank(Joystick *stick) {
	float left = 0, right = 0;
	if (stick->GetY() > 0.1 || stick->GetY() < -0.1)
		left = stick->GetY();
	if (stick->GetRawAxis(3) > 0.1 || stick->GetRawAxis(3) < -0.1)
		right = stick->GetRawAxis(3);
	this->deino->TankDrive(left, right, false);

}

void Chassis::DriveTank(float left, float right) {
	this->deino->TankDrive(left, right, false);
}
