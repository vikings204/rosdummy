#include "subsystems/DummySubsystem.h"

DummySubsystem::DummySubsystem() : 
SparkMaxes{
    // swerve modules
    rev::spark::SparkMax{10, rev::spark::SparkBase::MotorType::kBrushless},
    rev::spark::SparkMax{20, rev::spark::SparkBase::MotorType::kBrushless},
    rev::spark::SparkMax{11, rev::spark::SparkBase::MotorType::kBrushless},
    rev::spark::SparkMax{21, rev::spark::SparkBase::MotorType::kBrushless},
    rev::spark::SparkMax{12, rev::spark::SparkBase::MotorType::kBrushless},
    rev::spark::SparkMax{22, rev::spark::SparkBase::MotorType::kBrushless},
    rev::spark::SparkMax{13, rev::spark::SparkBase::MotorType::kBrushless},
    rev::spark::SparkMax{23, rev::spark::SparkBase::MotorType::kBrushless},
},
ServoHub{8}
{
    std::cout << "initialized spark maxes\n";
}


void DummySubsystem::Periodic() {
    // nothing lmao
}