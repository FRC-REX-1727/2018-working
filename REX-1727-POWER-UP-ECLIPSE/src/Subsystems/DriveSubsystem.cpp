#include "DriveSubsystem.hpp"

DriveSubsystem::DriveSubsystem() : frc::Subsystem("DriveSubsystem") {
    std::cout << "DriveSubsystem constructor called ..." << std::endl;
    left_drive = RobotMap::left_drive;
    right_drive = RobotMap::right_drive;
    tank_drive = RobotMap::tank_drive;
    left_drive_vel_PID = RobotMap::left_drive_vel_PID;
    left_drive_vel_PID->Disable();
    right_drive_vel_PID = RobotMap::right_drive_vel_PID;
    right_drive_vel_PID->Disable();
//    left_drive_dist_PID = RobotMap::left_drive_dist_PID;
//    left_drive_dist_PID->Disable();
//    right_drive_dist_PID = RobotMap::right_drive_dist_PID;
//    right_drive_dist_PID->Disable();
    left_drive_enc = RobotMap::left_drive_enc;
    right_drive_enc = RobotMap::right_drive_enc;
    std::cout << "DriveSubsystem constructor ended." << std::endl;
}

void DriveSubsystem::SetDriveRaw(double left, double right, bool squared) {
    tank_drive->TankDrive(-left, right, squared);
}

void DriveSubsystem::InitDefaultCommand() {
}

void DriveSubsystem::Periodic() {
}

void DriveSubsystem::DriveDist(double dist) {
    int sign = dist < 0 ? -1 : 1;
    while (std::abs(left_drive_enc->GetDistance()) < std::abs(dist)) {
        SetDriveRaw(sign*0.75, sign*0.75, false);
    }
}

void DriveSubsystem::Turn(double deg) {
    constexpr double pi = 3.14159265358979323846;
    double dist = 24 * pi * (deg / 360);
    int sign = dist < 0 ? -1 : 1;
    while (std::abs(left_drive_enc->GetDistance()) < std::abs(dist)) {
        SetDriveRaw(sign*0.50, -sign*0.50, false);
    }
}

double DriveSubsystem::GetEncDist(DriveSide s) {
    switch (s) {
        case left: {
            return left_drive_enc->GetDistance();
        } case right: {
            return right_drive_enc->GetDistance();
        } case both: {
            return 0;
        }
    }
    return 0;
}

/* void DriveSubsystem::DriveDist(double dist, DriveSide side) { */
/*     frc::Timer timer; */
/*     timer.Reset(); */
/*     timer.Start(); */
/*     RobotMap::ResetEncoders(); */

/*     int sign = 1; */
/*     if (dist < 0) */
/*         sign = -1; */

/*     while (1) { */
/*         if (std::abs(left_drive_enc->Get()) < std::abs(dist) && (side == left || side == both)) */
/*             left_drive->Set(0.75 * sign); */
/*         if (std::abs(right_drive_enc->Get()) < std::abs(dist) && (side == right || side == both)) */
/*             right_drive->Set(0.75 * sign); */
/*         if () */
/*     } */
/* } */
