#include "TurnCommand.hpp"

TurnCommand::TurnCommand(double d, double s,Direction rl) :
        frc::Command("Turn Command"),
        start_l(Robot::drive_subsystem->GetEncDist(DriveSubsystem::left)),
        start_r(Robot::drive_subsystem->GetEncDist(DriveSubsystem::right)) {
    Requires(Robot::drive_subsystem.get());
//    constexpr double pi = 3.14159265358979323846;
    speed = s;
    constexpr double pi = 3.14159265358979323846;
	deg = d;
	dist = 24 * pi * (deg / 360);
    dir = rl;
}

void TurnCommand::Initialize() {
	RobotMap::right_drive_vel_PID->Reset();
	RobotMap::left_drive_vel_PID->Reset();
	RobotMap::right_drive_vel_PID->SetSetpoint(dir == Direction::left ? -speed : speed);
	RobotMap::left_drive_vel_PID->SetSetpoint(dir == Direction::left ? -speed : speed);
	RobotMap::right_drive_vel_PID->Enable();
	RobotMap::left_drive_vel_PID->Enable();
}

void TurnCommand::Execute() {

//	dir = currangle > deg ? Direction::left : Direction::right;
//	RobotMap::right_drive_vel_PID->SetSetpoint(dir == Direction::left ? -speed : speed);
//	RobotMap::left_drive_vel_PID->SetSetpoint(dir == Direction::left ? -speed : speed);

}

bool TurnCommand::IsFinished() {
	double left = std::abs(Robot::drive_subsystem->GetEncDist(DriveSubsystem::left)) - start_l;
	double right = std::abs(Robot::drive_subsystem->GetEncDist(DriveSubsystem::right)) - start_r;
	return  left > std::abs(dist) && right > std::abs(dist);
}

void TurnCommand::End() {
	RobotMap::right_drive_vel_PID->Disable();
	RobotMap::left_drive_vel_PID->Disable();
	RobotMap::right_drive_vel_PID->Reset();
	RobotMap::left_drive_vel_PID->Reset();
    Robot::drive_subsystem->SetDriveRaw(0, 0, false);
}

void TurnCommand::Interrupted() {
	RobotMap::right_drive_vel_PID->Disable();
	RobotMap::left_drive_vel_PID->Disable();
	RobotMap::right_drive_vel_PID->Reset();
	RobotMap::left_drive_vel_PID->Reset();
    Robot::drive_subsystem->SetDriveRaw(0, 0, false);
}
