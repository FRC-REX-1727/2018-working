#include "CubeCommand.hpp"

CubeCommand::CubeCommand() {
    Requires(Robot::arm_subsystem.get());
    Requires(Robot::intake_subsystem.get());
}

void CubeCommand::Initialize() {
    std::cout << "CubeCommand initialized." << std::endl;
}

void CubeCommand::Execute() {
    auto xbox = Robot::oi->GetXboxController();
    auto logitech = Robot::oi->GetLogitech();

    constexpr auto right = frc::GenericHID::kRightHand;
    constexpr auto left = frc::GenericHID::kLeftHand;

    if (xbox->GetBumperPressed(left))
        SetArm(lift);
    else if (xbox->GetBumperPressed(right))
        SetArm(drop);

    if (xbox->GetTriggerAxis(left) > 0.25)
        Robot::arm_subsystem->SetIntake(-xbox->GetTriggerAxis(left));
    else if (logitech->GetRawButton(2))
        Robot::arm_subsystem->SetIntake(ArmSubsystem::intake);
    else if (logitech->GetRawButton(1))
        Robot::arm_subsystem->SetIntake(ArmSubsystem::outtake);
    else
        Robot::arm_subsystem->SetIntake(ArmSubsystem::off);

    /* if (logitech->GetRawButtonPressed(7)) */
    /*     Robot::intake_subsystem->SetPosition(IntakeSubsystem::grip); */
    /* else if (logitech->GetRawButtonPressed(8)) */
    /*     Robot::intake_subsystem->SetPosition(IntakeSubsystem::deploy); */

    if (logitech->GetRawButtonPressed(7) || logitech->GetRawButtonPressed(8))
        Robot::intake_subsystem->Toggle();

    /* if (logitech->GetRawButton(9) || logitech->GetRawButton(2)) */
    /*     Robot::intake_subsystem->SetIntake(IntakeSubsystem::intake); */
    /* else if (logitech->GetRawButton(10)) */
    /*     Robot::intake_subsystem->SetIntake(IntakeSubsystem::outtake); */
    /* else */
    /*     Robot::intake_subsystem->SetIntake(IntakeSubsystem::off); */

    if (logitech->GetRawButton(1))
        Robot::intake_subsystem->SetIntake(IntakeSubsystem::outtake);
    else if (logitech->GetRawButton(2))
        Robot::intake_subsystem->SetIntake(IntakeSubsystem::intake);
    else if (logitech->GetRawButton(5))
        Robot::intake_subsystem->SetIntake(IntakeSubsystem::spin_left);
    else if (logitech->GetRawButton(3))
        Robot::intake_subsystem->SetIntake(IntakeSubsystem::spin_right);
    else
        Robot::intake_subsystem->SetIntake(IntakeSubsystem::off);
}

bool CubeCommand::IsFinished() {
    return false;
}

void CubeCommand::End() {
    SetArm(lift);
}

void CubeCommand::Interrupted() {
}

void CubeCommand::SetArm(ArmAction a) {
    switch (a) {
        case lift: {
            Robot::intake_subsystem->SetPosition(IntakeSubsystem::deploy);
            Robot::arm_subsystem->SetArm(ArmSubsystem::lift);
            std::thread t(DelayToggle, 2.0);
            t.detach();
            break;
        } case drop: {
            Robot::intake_subsystem->SetPosition(IntakeSubsystem::deploy);
            Robot::arm_subsystem->SetArm(ArmSubsystem::drop);
            break;
        }
    }
}

void CubeCommand::ToggleArm() {
    if (Robot::arm_subsystem->GetRaised())
        SetArm(drop);
    else
        SetArm(lift);
}

void CubeCommand::DelayToggle(double s) {
    frc::Timer t;
    t.Start();
    auto starting = Robot::intake_subsystem->GetOpened();
    while (t.Get() < s) {
        if (starting != Robot::intake_subsystem->GetOpened())
            return;
    }
    Robot::intake_subsystem->SetPosition(IntakeSubsystem::grip);
}
