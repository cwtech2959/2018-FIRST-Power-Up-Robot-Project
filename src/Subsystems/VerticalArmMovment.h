/*
 * VerticalArmMovment.h
 *
 *  Created on: Feb 10, 2018
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_VERTICALARMMOVMENT_H_
#define SRC_SUBSYSTEMS_VERTICALARMMOVMENT_H_

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>

enum CubeVerticalPlace
{
	Exchange = 0,
	Level2 = 1,
	Level3 = 2,
	Portal = 3,
	Switch = 4,
	Scale = 5
};

class VerticalArmMovment: public frc::Subsystem
{
private:
	WPI_TalonSRX m_cubeLiftMotor;

public:
	VerticalArmMovment();
	virtual ~VerticalArmMovment();

	void MoveArm(CubeVerticalPlace target, double height = 0.0);
};

#endif /* SRC_SUBSYSTEMS_VERTICALARMMOVMENT_H_ */
