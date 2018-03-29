/*
 * VelocityTuningCommand.cpp
 *
 *  Created on: Mar 19, 2018
 *      Author: anton
 */

#include <Commands/VelocityTuningCommand.h>

VelocityTuningCommand::VelocityTuningCommand() {
	// TODO Auto-generated constructor stub
	Requires(Robot::drive_subsystem.get());


}


void VelocityTuningCommand::Initialize()
{
	RobotMap::right_drive_enc->Reset();
	RobotMap::left_drive_enc->Reset();
	RobotMap::right_drive_vel_PID->Reset();
	RobotMap::left_drive_vel_PID->Reset();
	RobotMap::right_drive_vel_PID->SetPID(.0005,0.001,0,1/84.3);
	RobotMap::left_drive_vel_PID->SetPID(.0005,0.001,0,1/84.3);
	RobotMap::right_drive_vel_PID->SetSetpoint(-36);
	RobotMap::left_drive_vel_PID->SetSetpoint(36);
	RobotMap::right_drive_vel_PID->Enable();
	RobotMap::left_drive_vel_PID->Enable();

}
void VelocityTuningCommand::Execute()
{
	//RobotMap::left_drive_vel_PID->SetSetpoint(-RobotMap::right_drive_enc->GetRate());
}
bool VelocityTuningCommand::IsFinished()
{
	return false;
}
void VelocityTuningCommand::End()
{

}
void VelocityTuningCommand::Interrupted()
{

}
