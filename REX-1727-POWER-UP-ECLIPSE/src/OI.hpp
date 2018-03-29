/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <iostream>
#include <thread>

#include <XboxController.h>
#include <Joystick.h>
#include <SmartDashboard/SmartDashboard.h>
#include <SmartDashboard/Sendable.h>
#include <CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "RobotMap.hpp"

class OI {
    public:
        OI();
        ~OI();
        std::shared_ptr<frc::XboxController> GetXboxController() const;
        std::shared_ptr<frc::Joystick> GetLogitech() const;
        void SetDashboard();
        void StartCameras();
    private:
        std::shared_ptr<frc::XboxController> xbox_controller;
        std::shared_ptr<frc::Joystick> logitech_joy;
        static void LifeCamThread();
};
