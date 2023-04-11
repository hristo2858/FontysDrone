#ifndef MOTOR_MIXING_ALGORITHM_H
#define MOTOR_MIXING_ALGORITHM_H

#include "./../../Hardware/Abstractions/IMotor.h"

class IMotorMixingAlgorithm {
public:
	virtual void setMotorCorrections(float rollCorrection, float pitcCorrection, float yawCorrection, float thrustCorrection, IMotor* motors);
};

#endif