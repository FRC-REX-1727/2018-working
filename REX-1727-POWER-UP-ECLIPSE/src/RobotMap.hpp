/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <memory>
#include <iostream>
#include <cmath>

#include <Drive/DifferentialDrive.h>
#include <Spark.h>
#include <Encoder.h>
#include <PIDController.h>
#include <DoubleSolenoid.h>
#include <VictorSP.h>
#include <PowerDistributionPanel.h>
#include <Compressor.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <cscore_oo.h>
#include <ADXRS450_Gyro.h>
#include "AnglePIDOutput.h"
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

namespace ctre {
    typedef ctre::phoenix::motorcontrol::can::TalonSRX CANTalonSRX;
}

class RobotMap {
    public:
        static std::shared_ptr<frc::Spark> left_drive;
        static std::shared_ptr<frc::Spark> right_drive;
        static std::shared_ptr<frc::Encoder> left_drive_enc;
        static std::shared_ptr<frc::Encoder> right_drive_enc;
        static std::shared_ptr<frc::DifferentialDrive> tank_drive;
        static std::shared_ptr<frc::PIDController> left_drive_vel_PID;
        static std::shared_ptr<frc::PIDController> left_drive_dist_PID;
        static std::shared_ptr<frc::PIDController> right_drive_vel_PID;
        static std::shared_ptr<frc::PIDController> right_drive_dist_PID;
        static std::shared_ptr<frc::ADXRS450_Gyro> spi_gyro;
        static std::shared_ptr<frc::PIDController> angle_controller;
        static std::shared_ptr<AnglePIDOutput> angle_output;


        static std::shared_ptr<frc::VictorSP> left_climber;
        static std::shared_ptr<frc::VictorSP> right_climber;
        static std::shared_ptr<frc::DoubleSolenoid> climber_solenoid;
        static std::shared_ptr<frc::DoubleSolenoid> brake_solenoid;

        static std::shared_ptr<frc::DoubleSolenoid> arm_solenoid;
        static std::shared_ptr<ctre::CANTalonSRX> left_internal_intake;
        static constexpr int left_talon = 0;
        static std::shared_ptr<ctre::CANTalonSRX> right_internal_intake;
        static constexpr int right_talon = 1;
        static std::shared_ptr<frc::Spark> left_external_intake;
        static std::shared_ptr<frc::DoubleSolenoid> intake_solenoid;
        static std::shared_ptr<frc::Spark> right_external_intake;

        static std::shared_ptr<frc::PowerDistributionPanel> pdp;
        static constexpr int pdp_num = 3;
        static std::shared_ptr<frc::Compressor> compressor;
        static constexpr int pcm_num = 2;

        static void init();
        static void ResetEncoders();
};
