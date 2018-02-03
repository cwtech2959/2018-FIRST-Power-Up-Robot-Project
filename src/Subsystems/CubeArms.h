/*
 * CubeArms.h
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#ifndef SRC_CUBE_ARMS_H_
#define SRC_CUBE_ARMS_H_

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>

class CubeArms: public frc::Subsystem
{
private:
	// private members
	frc::DoubleSolenoid m_foldArms {0, 1};

public:
	CubeArms();
	~CubeArms() override = default;

	void FoldUp();
	void FoldDown();
};

#endif /* SRC_CUBE_ARMS_H_ */
