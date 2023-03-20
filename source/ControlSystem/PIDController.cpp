#include "ControlSystem/PIDController.h";

PIDController::PIDController(int Kp, int Ki, int Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
}

float PIDController::getCorrection(float error) {
	return 0;
}