#include "DriveCommand.hpp"

DriveCommand::DriveCommand() : frc::Command() {
    Requires(Robot::drive_subsystem.get());
}

void DriveCommand::Initialize() {
    std::cout << "DriveCommand initialized." << std::endl;
}

void DriveCommand::Execute() {
    auto xbox = Robot::oi->GetXboxController();

    constexpr auto right = frc::GenericHID::kRightHand;
    constexpr auto left = frc::GenericHID::kLeftHand;

    if (xbox->GetTriggerAxis(right) >= 0.25) {
        Robot::drive_subsystem->SetDriveRaw(
                xbox->GetY(left) * 0.4,
                -xbox->GetY(right) * 0.4,
                false);
    } else {
        Robot::drive_subsystem->SetDriveRaw(
                xbox->GetY(left),
                -xbox->GetY(right),
                true);
    }
}

bool DriveCommand::IsFinished() {
    return false;
}

void DriveCommand::End() {
}

void DriveCommand::Interrupted() {
}
