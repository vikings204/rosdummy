#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/DriverStation.h>
#include <networktables/GenericEntry.h>

#include "subsystems/DummySubsystem.h"
#include "subsystems/RobotStateSubsystem.h"

class RobotContainer {
public:
    RobotContainer();

	void CheckDriverStationUpdate();
private:
	DummySubsystem Dummy;
	RobotStateSubsystem RobotState;

	frc::DriverStation::Alliance alliance;
	std::string allianceString = "never init";
};