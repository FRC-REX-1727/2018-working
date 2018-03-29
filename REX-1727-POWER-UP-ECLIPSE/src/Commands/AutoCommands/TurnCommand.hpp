#pragma once

#include <cmath>

#include <Commands/Command.h>

#include "../../Robot.hpp"

class TurnCommand : public frc::Command {
    public:
		enum Direction {right, left};
        TurnCommand(double,double,Direction);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
    private:
        double deg;
        double speed;
        Direction dir;
        double dist;
        double const start_l;
        double const start_r;
};
