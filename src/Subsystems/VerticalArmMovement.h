/*
 * VerticalArmMovment.h
 *
 *  Created on: Feb 10, 2018
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_VERTICALARMMOVEMENT_H_
#define SRC_SUBSYSTEMS_VERTICALARMMOVEMENT_H_

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"
#include <DigitalInput.h>

class VerticalArmMovement: public frc::Subsystem
{
private:
	WPI_TalonSRX m_cubeLiftMotor;
	frc::DigitalInput m_atBottomSwitch;

	 // approximately 24" of travel with diameter of 1.08 for an encoder with 4096 ticks
//	const double GearDiameter = Pi * 1.08;
//	const double DistanceToTicksFactor = 4096 / GearDiameter;

	const double ScaleHeightMinimum = 4.0;	// in feet
	const double ScaleHeightMaximum = 6.0;
	const double ScalePositionMaximum = 30000;
	const double ScalePositionMinimum = 27650;
	const double ScaleConversionSlope = (ScalePositionMaximum-ScalePositionMinimum)/(ScaleHeightMaximum-ScaleHeightMinimum);

	const double Level1Position = 0;
	const double ExchangePosition = 750;
	const double Level2Position = 4700;
	const double SwitchPosition = 11000;
	const double PortalPosition = 9450;
	const double Level3Position = 9450;

public:
	enum CubeVerticalPlace
	{
		Level1 = 0,
		Exchange = 1,
		Level2 = 2,
		Level3 = 3,
		Portal = 4,
		Switch = 5,
		Scale = 6
	};

public:
	VerticalArmMovement();
	~VerticalArmMovement() override = default;

	void InitDefaultCommand() override;

	void MoveArm(CubeVerticalPlace target, double scaleHeight = 0.0);
	void MoveArmToHeight(double height);
	void MoveToAbsoluteHeight(double height);
	bool IsAtPosition(CubeVerticalPlace target, double scaleHeight = 0.0);
	bool IsAtSwitchOrHigher();
	void UpdateSmartDashboard();

	bool AtBottom();
	void AtBottomReset();
};

#endif /* SRC_SUBSYSTEMS_VERTICALARMMOVEMENT_H_ */
