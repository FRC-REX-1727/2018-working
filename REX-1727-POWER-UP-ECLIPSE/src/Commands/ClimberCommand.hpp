#pragma once

#include "Commands/Command.h"
#include "../Robot.hpp"

class ClimberCommand: public frc::Command {
    public:
        ClimberCommand();

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
};
