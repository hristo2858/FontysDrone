#ifndef MOTOR_CORRECTIONS_TO_PWM_SIGNAL_CONVERTER_H
#define MOTOR_CORRECTIONS_TO_PWM_SIGNAL_CONVERTER_H

class IMotorCorrectionsToPWMSignalConverter {
	public:
		virtual float* Convert(float* motorCorrections);
};

#endif