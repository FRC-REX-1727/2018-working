#include "AutoCommandGroup.hpp"

AutoCommandGroup::AutoCommandGroup(std::string&& info, char&& c):
        frc::CommandGroup("Auto Group"),
        position(c),
        switch_pos(info[0]) {

    AddParallel(new DeployCommand());
    AddSequential(new DistanceCommand(107,36));
//    AddSequential(new TurnCommand(90,12,TurnCommand::Direction::left));

    if (position == switch_pos) {
        AddSequential(new DropCommand());
    }
}

void AutoCommandGroup::Initialize() {
}

void AutoCommandGroup::Execute() {
}

bool AutoCommandGroup::IsFinished() {
    return false;
}

void AutoCommandGroup::Interrupted() {
}

void AutoCommandGroup::End() {
}
