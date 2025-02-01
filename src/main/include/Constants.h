#pragma once

#include <string>

namespace Constants {
    const int XBOX_DRIVER_ID = 1;
    const int XBOX_OPERATOR_ID = 2;

    const std::string JETSON_IP = "10.2.4.50";
    const std::string JETSON_UDP_HOST = "udp://" + JETSON_IP + ":58";

    enum Mode {
        UNKNOWN = 0,
        DISABLED = 1,
        AUTONOMOUS = 2,
        TELEOP = 3,
        TEST = 4,
        ESTOP = 5,
    };

    enum Alliance {
        NONE = 0,
        BLUE = 1,
        RED = 2,
    };
}