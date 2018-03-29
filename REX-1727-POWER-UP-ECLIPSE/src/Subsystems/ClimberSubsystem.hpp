#pragma once

#include <Commands/Subsystem.h>
#include <VictorSP.h>

#include "../RobotMap.hpp"

class ClimberSubsystem: public frc::Subsystem {
    public:
        enum ClimberAction {off, climb, drop};
        enum ClimberPosition {down = false, up = true};
        enum BrakePostition {disengage = false, engage = true};
        ClimberSubsystem();
        void InitDefaultCommand() override;
        void Periodic() override;
        void Deploy(ClimberPosition);
        void SetClimbMotors(double);
        void SetClimbMotors(ClimberAction);
        void SetBrake(BrakePostition);
    private:
        std::shared_ptr<frc::VictorSP> left_climber;
        std::shared_ptr<frc::VictorSP> right_climber;
        std::shared_ptr<frc::DoubleSolenoid> climber_solenoid;
        std::shared_ptr<frc::DoubleSolenoid> brake_solenoid;
};
