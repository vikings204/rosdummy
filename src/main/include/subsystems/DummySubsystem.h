#pragma once

#include <vector>
#include <iostream>

#include "frc2/command/SubsystemBase.h"
#include <rev/SparkMax.h>
#include <rev/ServoHub.h>

class DummySubsystem : public frc2::SubsystemBase {
public:
    DummySubsystem();

    void Periodic() override;

private:
    rev::spark::SparkMax SparkMaxes[8]; // using vector resulted in "error: use of deleted function"
    //rev::servohub::ServoHub ServoHub;
};