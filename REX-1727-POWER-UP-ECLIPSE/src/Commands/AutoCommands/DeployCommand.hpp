#pragma once

#include <Commands/Command.h>
#include <Timer.h>

#include "../../Robot.hpp"

class DeployCommand : public frc::Command {
    public:
        DeployCommand();
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
    private:
        frc::Timer t;
};
