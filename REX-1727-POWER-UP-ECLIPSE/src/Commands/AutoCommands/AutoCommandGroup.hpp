#pragma once

#include <cmath>

#include <Commands/CommandGroup.h>

#include "DistanceCommand.hpp"
#include "TurnCommand.hpp"
#include "DropCommand.hpp"
#include "DeployCommand.hpp"
#include "../../Robot.hpp"

class AutoCommandGroup : public frc::CommandGroup {
    public:
        AutoCommandGroup(std::string&&, char&&);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
    private:
        char position;
        char switch_pos;
};
