#include "subsystems/XboxSubsystem.h"

XboxSubsystem::XboxSubsystem() :
DRIVER{Constants::XBOX_DRIVER_ID},
OPERATOR{Constants::XBOX_OPERATOR_ID},
ctx{1},
sock{ctx, zmq::socket_type::pub}
{
    sock.connect(Constants::JETSON_UDP_HOST + "02");
    std::cout << "initialized xbox controllers\n";
}

void XboxSubsystem::Periodic() {
    ControllerState driverState{
        .A = DRIVER.GetAButton(),
        .B = DRIVER.GetBButton(),
        .X = DRIVER.GetXButton(),
        .Y = DRIVER.GetYButton(),
        .LB = DRIVER.GetLeftBumperButton(),
        .RB = DRIVER.GetRightBumperButton(),
        .BACK = DRIVER.GetBackButton(),
        .START = DRIVER.GetStartButton(),
        .LSB = DRIVER.GetLeftStickButton(),
        .RSB = DRIVER.GetRightStickButton(),
        .LSX = DRIVER.GetLeftX(),
        .LSY = DRIVER.GetLeftY(),
        .RSX = DRIVER.GetRightX(),
        .RSY = DRIVER.GetRightY(),
        .POV = DRIVER.GetPOV(),
        .LT = DRIVER.GetLeftTriggerAxis(),
        .RT = DRIVER.GetRightTriggerAxis(),
    };

    ControllerState operatorState{
        .A = OPERATOR.GetAButton(),
        .B = OPERATOR.GetBButton(),
        .X = OPERATOR.GetXButton(),
        .Y = OPERATOR.GetYButton(),
        .LB = OPERATOR.GetLeftBumperButton(),
        .RB = OPERATOR.GetRightBumperButton(),
        .BACK = OPERATOR.GetBackButton(),
        .START = OPERATOR.GetStartButton(),
        .LSB = OPERATOR.GetLeftStickButton(),
        .RSB = OPERATOR.GetRightStickButton(),
        .LSX = OPERATOR.GetLeftX(),
        .LSY = OPERATOR.GetLeftY(),
        .RSX = OPERATOR.GetRightX(),
        .RSY = OPERATOR.GetRightY(),
        .POV = OPERATOR.GetPOV(),
        .LT = OPERATOR.GetLeftTriggerAxis(),
        .RT = OPERATOR.GetRightTriggerAxis(),
    };

    ControlUpdate update{
        .DRIVER = driverState,
        .OPERATOR = operatorState,
    };

    auto res = sock.send(zmq::buffer(msgpack::pack(update)), zmq::send_flags::none);
    res.reset();
}