/*
 * CubeDeliverySubsystem.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: Andrew
 */

#include "Subsystems/CubeDelivery.h"
#include "RobotMap.h"
#include <DoubleSolenoid.h>


CubeDelivery::CubeDelivery() : frc::Subsystem("CubeDeliverySubsystem"),
	m_openCloseArms {OPEN_CLOSE_CUBE_ARMS_FORWARD_SOLENOID, OPEN_CLOSE_CUBE_ARMS_REVERSE_SOLENOID},
	m_cubeManipulationMotor {CUBE_ARMS_OPEN_CLOSE_MOTOR},
	m_cubeLiftMotor {CUBE_VERTICAL_MOTOR_CAN}
{
}

void CubeDelivery::OpenArms()
{
	m_openCloseArms.Set(frc::DoubleSolenoid::Value::kForward);
}

void CubeDelivery::CloseArms()
{
	m_openCloseArms.Set(frc::DoubleSolenoid::Value::kReverse);
}

void CubeDelivery::StopWheels()
{
	m_cubeManipulationMotor.Set(0);
}

void CubeDelivery::SpinWheelsIn()
{
	m_cubeManipulationMotor.Set(1);
}

void CubeDelivery::SpinWheelsOut(double speed)
{
	if (speed < -1)
	{
		speed = -1;
	}
	else if (speed > 0)
	{
		speed = 0;
	}

	m_cubeManipulationMotor.Set(speed);
}

bool CubeDelivery::ArmsAreOpen()
{
	return m_openCloseArms.Get() == frc::DoubleSolenoid::Value::kForward;
}
