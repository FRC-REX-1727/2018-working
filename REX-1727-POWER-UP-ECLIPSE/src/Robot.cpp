#include "Robot.hpp"

std::unique_ptr<OI> Robot::oi;
std::unique_ptr<DriveSubsystem> Robot::drive_subsystem;
std::unique_ptr<ArmSubsystem> Robot::arm_subsystem;
std::unique_ptr<IntakeSubsystem> Robot::intake_subsystem;
std::unique_ptr<ClimberSubsystem> Robot::climber_subsystem;

void Robot::RobotInit() {
    std::cout << "Start of Robot::Init()..." << std::endl;
    chooser.AddDefault("Left", 'L');
    chooser.AddObject("Middle", 'M');
    chooser.AddObject("Right", 'R');
    frc::SmartDashboard::PutData("Starting position", &chooser);

    RobotMap::init();

    oi = std::make_unique<OI>();
    oi->SetDashboard();
    oi->StartCameras();

    drive_subsystem = std::make_unique<DriveSubsystem>();
    drive_command = std::make_shared<DriveCommand>();

    arm_subsystem = std::make_unique<ArmSubsystem>();
    intake_subsystem = std::make_unique<IntakeSubsystem>();
    cube_command = std::make_shared<CubeCommand>();

    climber_subsystem = std::make_unique<ClimberSubsystem>();
    climber_command = std::make_shared<ClimberCommand>();

    rumble_command = std::make_shared<RumbleCommand>();
    veltune_command = std::make_shared<VelocityTuningCommand>();
    frc::SmartDashboard::PutBoolean(
        		"Arm Raised",Robot::arm_subsystem->GetRaised());
        frc::SmartDashboard::PutBoolean(
        		"Intake Out",Robot::intake_subsystem->GetOpened());

}

void Robot::DisabledInit() {
    arm_subsystem->SetArm(ArmSubsystem::lift);
    intake_subsystem->SetPosition(IntakeSubsystem::grip);
}

void Robot::DisabledPeriodic() {
    frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
    char position = chooser.GetSelected();

    std::string game_data = frc::DriverStation::GetInstance().GetGameSpecificMessage();

    if (game_data.empty())
        game_data = "???";

    auto_command_grp = std::make_shared<AutoCommandGroup>(
            std::move(game_data), std::move(position));

    auto_command_grp->Start();
}

void Robot::AutonomousPeriodic() {
    frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
    RobotMap::ResetEncoders();
    drive_command->Start();
    cube_command->Start();
    //rumble_command->Start();
    climber_command->Start();

}

void Robot::TeleopPeriodic() {
    frc::Scheduler::GetInstance()->Run();
    std::cout << RobotMap::left_drive_enc->GetRate() << '\t'
    		  << RobotMap::right_drive_enc->GetRate() << '\t' << std::endl;
    oi->SetDashboard();
    frc::SmartDashboard::PutBoolean(
    	        		"Arm Raised",Robot::arm_subsystem->GetRaised());
	frc::SmartDashboard::PutBoolean(
    	        		"Intake Out",Robot::intake_subsystem->GetOpened());
}

void Robot::TestPeriodic() {

	oi->SetDashboard();
	frc::SmartDashboard::PutBoolean(
	        		"Arm Raised",Robot::arm_subsystem->GetRaised());
	frc::SmartDashboard::PutBoolean(
	        		"Intake Out",Robot::intake_subsystem->GetOpened());
}

START_ROBOT_CLASS(Robot)
