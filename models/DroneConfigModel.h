#include "../headers/Input/Abstractions/IFlyingInput.h"
#include "../headers/Input/Abstractions/ISensorInput.h"
#include "../headers/ControlSystem/Abstractions/IMotorMixingAlgorithm.h"
#include "../headers/ControlSystem/Abstractions/IFeedbackErrorHandler.h"
#include "../headers/ControlSystem/Abstractions/IController.h"
#include "../headers/ControlSystem/Abstractions/IWorldToBodyConverter.h"
#include "../headers/Hardware/Abstractions/IMotor.h"

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