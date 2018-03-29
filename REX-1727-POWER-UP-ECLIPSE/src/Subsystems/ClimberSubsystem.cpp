#include "ClimberSubsystem.hpp"

ClimberSubsystem::ClimberSubsystem() : frc::Subsystem("Climber Subsystem") {
    std::cout << "ClimberSubsystem constructor called ..." << std::endl;
    left_climber = RobotMap::left_climber;
    right_climber = RobotMap::right_climber;
    climber_solenoid = RobotMap::climber_solenoid;
    brake_solenoid = RobotMap::brake_solenoid;
    std::cout << "ClimberSubsystem constructor called ended." << std::endl;
}

void ClimberSubsystem::InitDefaultCommand() {

}

void ClimberSubsystem::Periodic() {

}

void ClimberSubsystem::Deploy(ClimberPosition p) {
    switch (p) {
        case down: {
            climber_solenoid->Set(frc::DoubleSolenoid::kForward);
            break;
        } case up: {
            climber_solenoid->Set(frc::DoubleSolenoid::kReverse);
            break;
        }
    }
}

void ClimberSubsystem::SetClimbMotors(double p) {
    left_climber->Set(p);
    right_climber->Set(p);
}

void ClimberSubsystem::SetClimbMotors(ClimberAction a) {
    switch (a) {
        case climb: {
            left_climber->Set(1.0);
            right_climber->Set(1.0);
            break;
        } case drop: {
            left_climber->Set(-1.0);
            right_climber->Set(-1.0);
            break;
        } case off: {
            left_climber->Set(0);
            right_climber->Set(0);
            break;
        }
    }
}

void ClimberSubsystem::SetBrake(BrakePostition p) {
    switch (p) {
        case engage: {
            brake_solenoid->Set(frc::DoubleSolenoid::kReverse);
            break;
        } case disengage: {
            brake_solenoid->Set(frc::DoubleSolenoid::kForward);
            break;
        }
    }
}
