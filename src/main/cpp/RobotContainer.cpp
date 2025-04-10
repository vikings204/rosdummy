#include "RobotContainer.h"

#include "zmq/zmq.hpp"

RobotContainer::RobotContainer() :
Dummy{},
RobotState{},
Xbox{}
{
	std::cout << "zmq version: " << std::to_string(get<0>(zmq::version())) << "." << std::to_string(get<0>(zmq::version())) << "." << std::to_string(get<0>(zmq::version())) << "\n";
}

void RobotContainer::CheckDriverStationUpdate() {
	auto allianceOpt = frc::DriverStation::GetAlliance();

	if (allianceOpt.has_value()) {
		//robotContainer.PoseEstimation.setAlliance(frc::DriverStation::Alliance::kBlue);
		alliance = allianceOpt.value();
		if (allianceOpt == frc::DriverStation::Alliance::kBlue) {
			allianceString = "Blue";
		} else if (allianceOpt == frc::DriverStation::Alliance::kRed) {
			allianceString = "Red";
		}
	}
}
