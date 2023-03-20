#include "DroneConfigModel.h"

DroneConfigModel model;

void setup() {
	//build the model here
}

void loop() {
	int xFlyingInput = model.FlyingInput.getX();
	int yFlyingInput = model.FlyingInput.getY();
	int zFlyingInput = model.FlyingInput.getZ();
	int yawFlyingInput = model.FlyingInput.getYaw();
	int estimationYawFlyingInput = model.FlyingInput.getEstimationYaw();

	int altitudeSensorInput = model.SensorInput.getAltitude();
	int yawSensorInput = model.SensorInput.getYaw();
	int pitchSensorInput = model.SensorInput.getPitch();
	int rollSensorInput = model.SensorInput.getRoll();
	int xSensorInput = model.SensorInput.getX();
	int ySensorInput = model.SensorInput.getY();

	int worldToBodyRollError = model.WorldToBodyConverter.getWorldToBodyRollCorrection(estimationYawFlyingInput, xFlyingInput, yFlyingInput, xSensorInput, ySensorInput);
	int worldToBodyPitchError = model.WorldToBodyConverter.getWorldToBodyPitchCorrection(estimationYawFlyingInput, xFlyingInput, yFlyingInput, xSensorInput, ySensorInput);

	int worldToBodyRollCorrection = model.WorldToBodyRollController.getCorrection(worldToBodyRollError);
	int worldToBodyPitchCorrection = model.WorldToBodyPitchController.getCorrection(worldToBodyPitchError);

	int rowError = model.ErrorHandler.getError(rollSensorInput, worldToBodyRollCorrection);
	int pitchError = model.ErrorHandler.getError(pitchSensorInput, worldToBodyPitchCorrection);
	int yawError = model.ErrorHandler.getError(yawFlyingInput, yawSensorInput);
	int altitudeError = model.ErrorHandler.getError(altitudeSensorInput, zFlyingInput);

	int rollCorrection = model.RollController.getCorrection(rowError);
	int pitchCorrection = model.RollController.getCorrection(pitchError);
	int yawCorrection = model.RollController.getCorrection(yawError);
	int altitudeCorrection = model.RollController.getCorrection(altitudeError);

	model.MotorMixingAlgorithm.setMotorCorrections(rollCorrection, pitchCorrection, yawCorrection, altitudeCorrection, model.FlyingMotors);

}
