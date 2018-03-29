/*
 * AnglePIDOutput.h
 *
 *  Created on: Mar 19, 2018
 *      Author: anton
 */

#ifndef SRC_ANGLEPIDOUTPUT_H_
#define SRC_ANGLEPIDOUTPUT_H_

#include <PIDOutput.h>

class AnglePIDOutput: public frc::PIDOutput {
public:
	AnglePIDOutput();
	virtual ~AnglePIDOutput();
	void PIDWrite(double);
	double GetOutput();
private:
	double out;
};

#endif /* SRC_ANGLEPIDOUTPUT_H_ */
