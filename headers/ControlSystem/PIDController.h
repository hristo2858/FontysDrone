#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include "Abstractions/IController.h";

class PIDController : public IController {
public:
	PIDController(float Kp, float Ki, float Kd, float outputMin, float outputMax, float updateRate);
	float getCorrection(float error);

protected:
	float Kp;
	float Kd;
	float Ki;
	float OutputMin;
	float OutputMax;
	float UpdateRate;
	float IntegralTerm = 0;
	float DerivativeTerm = 0;
	float PrevError = 0;
	float Clamp(float variableToClamp);
};

#endif