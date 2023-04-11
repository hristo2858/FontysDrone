#include "./../../headers/ControlSystem/PIDController.h";

PIDController::PIDController(float Kp, float Ki, float Kd, float outputMin, float outputMax, float updateRate) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	this->OutputMin = outputMin;
	this->OutputMax = outputMax;
	this->UpdateRate = updateRate;
}

float PIDController::getCorrection(float error) {
	this->IntegralTerm += this->IntegralTerm + (error * this->UpdateRate);
	this->IntegralTerm = this->Clamp(this->IntegralTerm);

	this->DerivativeTerm = (error - this->PrevError) / this->UpdateRate;
	this->DerivativeTerm = this->Clamp(this->DerivativeTerm);

	this->PrevError = error;
	float output = (this->Kp * error) + (this->Ki * this->IntegralTerm) + (this->Kd * this->DerivativeTerm);

	return this->Clamp(output);
}

float PIDController::Clamp(float variableToClamp) {
	if (variableToClamp <= this->OutputMin) { return this->OutputMin; }
	if (variableToClamp >= this->OutputMax) { return this->OutputMax; }
	return variableToClamp;
}