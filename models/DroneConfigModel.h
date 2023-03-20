#include "Input/IFlyingInput.h"
#include "Input/ISensorInput.h"
#include "ControlSystem/IMotorMixingAlgorithm.h"
#include "ControlSystem/IFeedbackErrorHandler.h"
#include "ControlSystem/IController.h"
#include "ControlSystem/IMotorCorrectionsToPWMSignalConverter.h"
#include "ControlSystem/IWorldToBodyConverter.h"
#include "Hardware/IMotor.h"

struct DroneConfigModel {
	public:
		IFlyingInput FlyingInput;
		ISensorInput SensorInput;

		IMotorMixingAlgorithm MotorMixingAlgorithm;

		IFeedbackErrorHandler ErrorHandler;

		IController RollController;
		IController PitchController;
		IController YawController;
		IController ThrustController;

		IController WorldToBodyRollController;
		IController WorldToBodyPitchController;
		IWorldToBodyConverter WorldToBodyConverter;

		IMotor* FlyingMotors;
};