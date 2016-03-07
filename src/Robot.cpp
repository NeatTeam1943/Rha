#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "RobotMap.h"
#include "Commands/Trigo/RaiseTrigo.h"
#include "Commands/Trigo/LowerTrigo.h"
#include "Commands/Auto/AutoGateRising2.h"
#include "Commands/Auto/AutoLowBar2.h"
#include "Commands/Auto/AutoSeeSaws2.h"

class Robot: public IterativeRobot {
private:
	Command *autonomousCommand;
	SendableChooser *chooser;
	void RobotInit() {
		CommandBase::init();
		SmartDashboard::PutData("Raise trigo", new RaiseTrigo(0.7));
		SmartDashboard::PutData("Lower trigo", new LowerTrigo(-0.7));
	}



	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */

	void DisabledInit() {
	}

	void DisabledPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit() {
		autonomousCommand = new AutoLowBar2();
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit() {
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

	}

	void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
		SmartDashboard::PutBoolean("Right up switch",
				CommandBase::trigo->IsUp(Trigo::TrigoSide::kRight));
		SmartDashboard::PutBoolean("Left up switch",
				CommandBase::trigo->IsUp(Trigo::TrigoSide::kLeft));
		SmartDashboard::PutBoolean("Right down switch",
				CommandBase::trigo->IsDown(Trigo::TrigoSide::kRight));
		SmartDashboard::PutBoolean("Left down switch",
				CommandBase::trigo->IsDown(Trigo::TrigoSide::kLeft));
		SmartDashboard::PutNumber("trigo power",
				CommandBase::oi->GetStick()->GetRawAxis(5));
		SmartDashboard::PutBoolean("Intake switch",
				CommandBase::intake->GetIsIn());
		SmartDashboard::PutBoolean("Auto Raise Trigo",
				CommandBase::trigo->IsAutoRaise());

	}

	void TestPeriodic() {
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

