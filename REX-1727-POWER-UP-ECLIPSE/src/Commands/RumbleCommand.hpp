#pragma once

#include <deque>
#include <cmath>

#include "Commands/Command.h"
#include "../Robot.hpp"

class RumbleCommand: public frc::Command {
    public:
        RumbleCommand();

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
    private:
        std::deque<double> currents;
};

