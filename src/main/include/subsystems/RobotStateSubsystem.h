#pragma once

#include <iostream>

#include <frc2/command/SubsystemBase.h>
#include <frc/DriverStation.h>
#include "zmq/zmq.hpp"
#include "msgpack/msgpack.hpp"
#include "Constants.h"

class RobotStateSubsystem : public frc2::SubsystemBase {
public:
    RobotStateSubsystem();

    void Periodic() override;

private:
    zmq::context_t ctx;
    zmq::socket_t sock;
};

struct RobotState {
    int Mode;
    int Alliance;
    bool DSConnected;
    bool FMSConnected;

    template<class T>
    void pack(T &pack) {
        pack(Mode);
    }
};