#include "ArmSubsystem.hpp"

ArmSubsystem::ArmSubsystem() : frc::Subsystem("ArmSubsystem") {
    std::cout << "ArmSubsystem constructor called ..." << std::endl;
    arm_solenoid = RobotMap::arm_solenoid;
    arm_solenoid->ClearAllPCMStickyFaults();
    left_internal_intake = RobotMap::left_internal_intake;
    right_internal_intake = RobotMap::right_internal_intake;
    raised = arm_solenoid->Get() == frc::DoubleSolenoid::kForward ? true : false;
    std::cout << "ArmSubsystem constructor ended." << std::endl;
}

void ArmSubsystem::Toggle() {
    if (raised)
        SetArm(drop);
    else
        SetArm(lift);
}

void ArmSubsystem::SetArm(ArmAction a) {
    switch (a) {
        case lift: {
            if (!raised) {
                arm_solenoid->Set(frc::DoubleSolenoid::kForward);
                raised = true;
            }
            break;
        } case drop: {
            if (raised) {
                arm_solenoid->Set(frc::DoubleSolenoid::kReverse);
                raised = false;
            }
            break;
        }
    }
}

void ArmSubsystem::SetIntake(IntakeAction i) {
    constexpr double pow = 1.0;
    auto mode = ctre::phoenix::motorcontrol::ControlMode::PercentOutput;
    switch (i) {
        case intake: {
            left_internal_intake->Set(mode, pow);
            right_internal_intake->Set(mode, -pow);
            break;
        } case outtake: {
            left_internal_intake->Set(mode, -pow);
            right_internal_intake->Set(mode, pow);
            break;
        } case off: {
            left_internal_intake->Set(mode, 0);
            right_internal_intake->Set(mode, 0);
            break;
        }
    }
}

void ArmSubsystem::SetIntake(double pow) {
    auto mode = ctre::phoenix::motorcontrol::ControlMode::PercentOutput;
    left_internal_intake->Set(mode, pow);
    right_internal_intake->Set(mode, -pow);
}

void ArmSubsystem::InitDefaultCommand() {
}

void ArmSubsystem::Periodic() {
}

bool ArmSubsystem::GetRaised() const {
    return raised;
}
