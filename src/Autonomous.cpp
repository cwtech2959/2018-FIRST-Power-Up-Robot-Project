/*
 * Autonomous.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: Kevin
 */

#include <Autonomous.h>
#include <iostream>
#include <SmartDashboard/SmartDashboard.h>
#include <DriverStation.h>
#include "Commands/Auto/DriveStraightCommand.h"
#include "Commands/Auto/MyAutoCommand.h"
#include "Commands/Auto/PlaceInitialCubeOnSwitchCommandGroup.h"
#include "Commands/Auto/PlaceOnLeftSwitchCommandGroup.h"
#include "Robot.h"

Autonomous::Autonomous()
{
	m_chooser.AddDefault("Default Auto", AutoCommand::Default);
	m_chooser.AddObject("Drive Straight", AutoCommand::DriveStraight);
	m_chooser.AddObject("Place Initial Cube On Switch", AutoCommand::PlaceInitialCubeOnSwitch);
	m_chooser.AddObject("Place Cube On Left Switch", AutoCommand::PlaceCubeOnLeftSwitch);
	frc::SmartDashboard::PutData("Autonomous Command", &m_chooser);
}

void Autonomous::AutoInit()
{
	Robot::CubeDeliverySubsystem->CloseArms();

	// Add code to read switch/scale state from Field Management System
	// https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/826278-2018-game-data-details
	auto gameData{frc::DriverStation::GetInstance().GetGameSpecificMessage()};
	if (gameData.size() < 3)
	{
		std::cout << "AutonomousInit - No game data.\n";
	}
	else
	{
		if (gameData[0] == 'L')
		{
			m_nearSwitchSide = Side::Left;
		}
		else
		{
			m_nearSwitchSide = Side::Right;
		}
		if (gameData[1] == 'L')
		{
			m_ScaleSide = Side::Left;
		}
		else
		{
			m_ScaleSide = Side::Right;
		}

		if (gameData[2] == 'L')
		{
			m_farSwitchSide = Side::Left;
		}
		else
		{
			m_farSwitchSide = Side::Right;
		}
	}

	switch(m_chooser.GetSelected())
	{
	case AutoCommand::Default:
		m_autonomousCommand = std::make_unique<MyAutoCommand>();
		break;
	case AutoCommand::DriveStraight:
		m_autonomousCommand = std::make_unique<DriveStraightCommand>(5.0);
		break;
	case AutoCommand::PlaceInitialCubeOnSwitch:
		m_autonomousCommand = std::make_unique<PlaceInitialCubeOnSwitchCommandGroup>();
		break;
	case AutoCommand::PlaceCubeOnLeftSwitch:
		m_autonomousCommand = std::make_unique<PlaceOnLeftSwitchCommandGroup>();
		break;
	}

	if(m_autonomousCommand)
	{
		std::cout << "Starting -- " << m_autonomousCommand->GetName() << '\n';
		m_autonomousCommand->Start();
	}
}

void Autonomous::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (m_autonomousCommand)
	{
		m_autonomousCommand->Cancel();
		m_autonomousCommand = nullptr;
	}
}

Autonomous::Side Autonomous::m_nearSwitchSide;
Autonomous::Side Autonomous::m_farSwitchSide;
Autonomous::Side Autonomous::m_ScaleSide;

Autonomous::Side Autonomous::GetNearSwitchSide()
{
	return m_nearSwitchSide;
}

Autonomous::Side Autonomous::GetFarSwitchSide()
{
	return 	m_farSwitchSide;
}

Autonomous::Side Autonomous::GetScaleSide()
{
	return m_ScaleSide;
}
