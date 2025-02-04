#include "subsystems/RobotStateSubsystem.h"

RobotStateSubsystem::RobotStateSubsystem() :
ctx{1},
sock{ctx, zmq::socket_type::pub}
{
    sock.connect(Constants::JETSON_CONN_PREFIX + "01");
    std::cout << "initialized robot state updater\n";
}

void RobotStateSubsystem::Periodic() {
    RobotState state;

    if (frc::DriverStation::IsEStopped()) {
        state.Mode = Constants::Mode::ESTOP;
    } else if (frc::DriverStation::IsDisabled()) {
        state.Mode = Constants::Mode::DISABLED;
    } else if (frc::DriverStation::IsAutonomousEnabled()) {
        state.Mode = Constants::Mode::AUTONOMOUS;
    } else if (frc::DriverStation::IsTeleopEnabled()) {
        state.Mode = Constants::Mode::TELEOP;
    } else if (frc::DriverStation::IsTestEnabled()) {
        state.Mode = Constants::Mode::TEST;
    } else {
        state.Mode = Constants::Mode::UNKNOWN;
    }

    auto allianceOpt = frc::DriverStation::GetAlliance();
    if (allianceOpt.has_value()) {
        auto val = allianceOpt.value();
        if (val == frc::DriverStation::Alliance::kBlue) {
            state.Alliance = Constants::Alliance::BLUE;
        } else if (val == frc::DriverStation::Alliance::kRed) {
            state.Alliance = Constants::Alliance::RED;
        } else {
            state.Alliance = Constants::Alliance::NONE;
        }
    } else {
        state.Alliance = Constants::Alliance::NONE;
    }

    if (frc::DriverStation::IsDSAttached()) {
        state.DSConnected = true;
    } else {
        state.DSConnected = false;
    }

    if (frc::DriverStation::IsFMSAttached()) {
        state.FMSConnected = true;
    } else {
        state.FMSConnected = false;
    }

    auto res = sock.send(zmq::buffer(msgpack::pack(state)), zmq::send_flags::none);
    if (res.has_value()) {
        std::cout << res.value();
    } else {
        std::cout << "failed to send robot state";
    }
    // res.reset();
}