#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include "Abstractions/IController.h";

class PIDController : public IController {
public:
	PIDController(int Kp, int Ki, int Kd);
	float getCorrection(float error);

protected:
	int Kp;
	int Kd;
	int Ki;
};

#endif