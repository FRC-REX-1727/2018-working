#include "DeployCommand.hpp"

DeployCommand::DeployCommand() : frc::Command("Deploy Command") {
    Requires(Robot::arm_subsystem.get());
    Requires(Robot::intake_subsystem.get());
}

void DeployCommand::Initialize() {
    Robot::arm_subsystem->SetArm(ArmSubsystem::lift);
    t.Reset();
    t.Start();
}

void DeployCommand::Execute() {
    if (t.Get() > 1.0)
        Robot::intake_subsystem->SetPosition(IntakeSubsystem::grip);
}

bool DeployCommand::IsFinished() {
    return Robot::arm_subsystem->GetRaised() && !Robot::intake_subsystem->GetOpened();
}

void DeployCommand::End() {

}

void DeployCommand::Interrupted() {
}
