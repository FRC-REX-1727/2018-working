#include "ClimberCommand.hpp"

ClimberCommand::ClimberCommand() : frc::Command() {
    Requires(Robot::climber_subsystem.get());
}

void ClimberCommand::Initialize() {
    std::cout << "ClimberCommand initiated." << std::endl;
}

void ClimberCommand::Execute() {
    auto logitech = Robot::oi->GetLogitech();

    if (logitech->GetRawButtonPressed(6))
        Robot::climber_subsystem->Deploy(ClimberSubsystem::up);
    else if (logitech->GetRawButtonPressed(4))
        Robot::climber_subsystem->Deploy(ClimberSubsystem::down);

    if (logitech->GetRawButton(11)) {
        Robot::climber_subsystem->SetBrake(ClimberSubsystem::disengage);
        Robot::climber_subsystem->SetClimbMotors(logitech->GetRawAxis(1));
    } else if (!logitech->GetRawButton(11)) {
        Robot::climber_subsystem->SetBrake(ClimberSubsystem::engage);
        Robot::climber_subsystem->SetClimbMotors(0);

    }
}

bool ClimberCommand::IsFinished() {
    return false;
}

void ClimberCommand::End() {
}

void ClimberCommand::Interrupted() {
}
