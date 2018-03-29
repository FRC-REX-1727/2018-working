#pragma once

#include <iostream>

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <Timer.h>

#include "../RobotMap.hpp"

class IntakeSubsystem : public frc::Subsystem {
    public:
        enum IntakeAction {intake, outtake, off, spin_left, spin_right};
        enum PostionAction {deploy = true, grip = false};
        IntakeSubsystem();
        void InitDefaultCommand() override;
        void Periodic() override;
        void Toggle();
        void SetPosition(PostionAction);
        void SetIntake(IntakeAction);
        void SetIntake(double);
        bool GetOpened() const;
    private:
        std::shared_ptr<frc::Spark> left_external_intake;
        std::shared_ptr<frc::Spark> right_external_intake;
        std::shared_ptr<frc::DoubleSolenoid> intake_solenoid;
        bool opened;
};
