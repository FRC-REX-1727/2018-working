#include "DistanceCommand.hpp"

DistanceCommand::DistanceCommand(double d,double s) :
        frc::Command("Drive Command"),
        start_l(Robot::drive_subsystem->GetEncDist(DriveSubsystem::left)),
        start_r(Robot::drive_subsystem->GetEncDist(DriveSubsystem::right)) {

    Requires(Robot::drive_subsystem.get());
    dist = d;
    speed = s;
}

void DistanceCommand::Initialize() {
	RobotMap::right_drive_vel_PID->Reset();
	RobotMap::left_drive_vel_PID->Reset();
	RobotMap::right_drive_vel_PID->SetSetpoint(-speed);
	RobotMap::left_drive_vel_PID->SetSetpoint(speed);
	RobotMap::right_drive_vel_PID->Enable();
	RobotMap::left_drive_vel_PID->Enable();
}

void DistanceCommand::Execute() {

    double left = std::abs(Robot::drive_subsystem->GetEncDist(DriveSubsystem::left) - start_l);

	double right = std::abs(Robot::drive_subsystem->GetEncDist(DriveSubsystem::right) - start_r);

	std::cout << RobotMap::left_drive_enc->GetRate() << '\t' << RobotMap::right_drive_enc->GetRate() << std::endl;
}

bool DistanceCommand::IsFinished() {
    double left = std::abs(Robot::drive_subsystem->GetEncDist(DriveSubsystem::left) - start_l);

    double right = std::abs(Robot::drive_subsystem->GetEncDist(DriveSubsystem::right) - start_r);

    return left > std::abs(dist) || right > std::abs(dist);
}

void DistanceCommand::End() {
    Robot::drive_subsystem->SetDriveRaw(0, 0, false);
	RobotMap::right_drive_vel_PID->Disable();
	RobotMap::left_drive_vel_PID->Disable();
	RobotMap::right_drive_vel_PID->Reset();
	RobotMap::left_drive_vel_PID->Reset();
}

void DistanceCommand::Interrupted() {
    Robot::drive_subsystem->SetDriveRaw(0, 0, false);
	RobotMap::right_drive_vel_PID->Disable();
	RobotMap::left_drive_vel_PID->Disable();
	RobotMap::right_drive_vel_PID->Reset();
	RobotMap::left_drive_vel_PID->Reset();
}
