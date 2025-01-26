#include "RobotContainer.h"

RobotContainer::RobotContainer() {
	
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
