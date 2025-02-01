#pragma once

#include <iostream>

#include "frc2/command/SubsystemBase.h"
#include <frc/XboxController.h>
#include "zmq/zmq.hpp"
#include "msgpack/msgpack.hpp"
#include "Constants.h"

class XboxSubsystem : public frc2::SubsystemBase {
public:
    XboxSubsystem();

    void Periodic() override;

private:
    frc::XboxController DRIVER;
    frc::XboxController OPERATOR;

    zmq::context_t ctx;
    zmq::socket_t sock;
};

struct ControllerState {
	bool A;
    bool B;
    bool X;
    bool Y;
    bool LB;
    bool RB;
    bool BACK;
    bool START;
    bool LSB;
    bool RSB;
    double LSX;
    double LSY;
    double RSX;
    double RSY;
    int POV;
    double LT;
    double RT;

	template<class T>
	void pack(T &pack) {
		pack(A, B, X, Y, LB, RB, BACK, START, LSB, RSB, LSX, LSY, RSX, RSY, POV, LT, RT);
	}
};

struct ControlUpdate {
    ControllerState DRIVER;
    ControllerState OPERATOR;

    template<class T>
    void pack(T &pack) {
        pack(DRIVER, OPERATOR);
    }
};