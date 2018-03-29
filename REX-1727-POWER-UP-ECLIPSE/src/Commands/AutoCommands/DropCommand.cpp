#include "DropCommand.hpp"

DropCommand::DropCommand() : frc::Command("Drop Command") {
    Requires(Robot::arm_subsystem.get());
}

void DropCommand::Initialize() {
    t.Reset();
    t.Start();
    Robot::arm_subsystem->SetArm(ArmSubsystem::lift);
}

void DropCommand::Execute() {
    if (t.Get() > 1)
        Robot::arm_subsystem->SetIntake(ArmSubsystem::outtake);
}

bool DropCommand::IsFinished() {
    // Probably won't last 10 seconds
    return t.Get() > 10;
}

void DropCommand::End() {
    Robot::arm_subsystem->SetIntake(ArmSubsystem::off);
}

void DropCommand::Interrupted() {
}
