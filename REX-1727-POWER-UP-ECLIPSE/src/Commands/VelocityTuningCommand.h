/*
 * VelocityTuningCommand.h
 *
 *  Created on: Mar 19, 2018
 *      Author: anton
 */

#ifndef SRC_COMMANDS_VELOCITYTUNINGCOMMAND_H_
#define SRC_COMMANDS_VELOCITYTUNINGCOMMAND_H_

#include <Commands/Command.h>
#include "../Robot.hpp"

class VelocityTuningCommand: public frc::Command {
	public:
		VelocityTuningCommand();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;
};

#endif /* SRC_COMMANDS_VELOCITYTUNINGCOMMAND_H_ */
