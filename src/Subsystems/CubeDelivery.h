/*
 * CubeDeliverySubsystem.h
 *
 *  Created on: Feb 3, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_CUBEDELIVERYSUBSYSTEM_H_
#define SRC_COMMANDS_CUBEDELIVERYSUBSYSTEM_H_

#include <Commands/Subsystem.h>
#include <Solenoid.h>
#include <Spark.h>
#include <DigitalInput.h>

// Cube Delivery Speeds
constexpr double SpinCubeWheelsOutSlow = -0.5;
constexpr double SpinCubeWheelsOutFast = -1.0;

class CubeDelivery: public frc::Subsystem
{
private:
	frc::Solenoid m_openCloseArms;
	frc::Spark m_cubeManipulationMotor;
	frc::DigitalInput m_cubePresentSwitch;

public:
	CubeDelivery();

	void OpenArms();
	void CloseArms();
	void StopWheels();
	void SpinWheelsIn();
	void SpinWheelsOut(double speed);
	bool ArmsAreOpen();
	bool CubePresent();

	void UpdateSmartDashboard();
};

#endif /* SRC_COMMANDS_CUBEDELIVERYSUBSYSTEM_H_ */
