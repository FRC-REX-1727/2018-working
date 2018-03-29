/*
 * AnglePIDOutput.cpp
 *
 *  Created on: Mar 19, 2018
 *      Author: anton
 */

#include <AnglePIDOutput.h>

AnglePIDOutput::AnglePIDOutput() {
	// TODO Auto-generated constructor stub

	out = 0;
}

AnglePIDOutput::~AnglePIDOutput() {
	// TODO Auto-generated destructor stub
}

void AnglePIDOutput::PIDWrite(double output)
{
	out = output;
}

double AnglePIDOutput::GetOutput()
{
	return out;
}

