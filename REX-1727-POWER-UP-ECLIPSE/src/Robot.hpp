#pragma once

#include <memory>
#include <algorithm>
#include <iostream>
#include <string>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <DriverStation.h>
#include <TimedRobot.h>
#include <SmartDashboard/SendableChooser.h>

#include "Commands/AutoCommands/AutoCommandGroup.hpp"
#include "Commands/DriveCommand.hpp"
#include "Commands/CubeCommand.hpp"
#include "Commands/RumbleCommand.hpp"
#include "Commands/ClimberCommand.hpp"
#include "Subsystems/DriveSubsystem.hpp"
#include "Subsystems/ArmSubsystem.hpp"
#include "Subsystems/IntakeSubsystem.hpp"
#include "Subsystems/ClimberSubsystem.hpp"
#include "RobotMap.hpp"
#include "OI.hpp"
#include "Commands/VelocityTuningCommand.h"

class Robot : public frc::TimedRobot {
    public:
        static std::unique_ptr<OI> oi;
        static std::unique_ptr<DriveSubsystem> drive_subsystem;
        static std::unique_ptr<ArmSubsystem> arm_subsystem;
        static std::unique_ptr<IntakeSubsystem> intake_subsystem;
        static std::unique_ptr<ClimberSubsystem> climber_subsystem;

        void RobotInit() override;
        void DisabledInit() override;
        void DisabledPeriodic() override;
        void AutonomousInit() override;
        void AutonomousPeriodic() override;
        void TeleopInit() override;
        void TeleopPeriodic() override;
        void TestPeriodic() override;

    private:
        frc::SendableChooser<char> chooser;

        std::shared_ptr<frc::Command> drive_command;
        std::shared_ptr<frc::Command> cube_command;
        std::shared_ptr<frc::Command> rumble_command;
        std::shared_ptr<frc::Command> climber_command;
        std::shared_ptr<frc::CommandGroup> auto_command_grp;
        std::shared_ptr<frc::Command> veltune_command;
};
