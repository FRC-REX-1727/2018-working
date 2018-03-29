#pragma once

#include <cmath>

#include <Commands/Command.h>
#include <Timer.h>

#include "../../Robot.hpp"

class DropCommand : public frc::Command {
    public:
        DropCommand();
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
    private:
        frc::Timer t;
};
