#include "RumbleCommand.hpp"

RumbleCommand::RumbleCommand() {
    currents.resize(10);
    currents.shrink_to_fit();
    for (auto& d : currents)
        d = 0;
}

void RumbleCommand::Initialize() {}

void RumbleCommand::Execute() {
//    auto joy = Robot::oi->GetXboxController();
//    auto pdp = RobotMap::pdp;
//    double curr = pdp->GetTotalCurrent();
//    double avg = 0;
//    currents.pop_front();
//    currents.push_back(curr);
//    for (const auto& d : currents)
//        avg += d;
//    avg /= 10;
//    joy->SetRumble(frc::GenericHID::RumbleType::kLeftRumble, std::abs((curr - avg) / 40));
//    joy->SetRumble(frc::GenericHID::RumbleType::kRightRumble, std::abs((curr - avg) / 40));
}

bool RumbleCommand::IsFinished() {
    return false;
}

void RumbleCommand::End() {}

void RumbleCommand::Interrupted() {}
