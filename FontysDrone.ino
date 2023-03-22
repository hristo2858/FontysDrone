#include <Arduino_BMI270_BMM150.h>

#include "models/DroneConfigModel.h"
#include "headers/Hardware/LSM9DS1_Accelerometer.h"
#include "headers/Hardware/LSM9DS1_Gyroscope.h"
#include "headers/Hardware/LSM9DS1_Magnetometer.h"

//DroneConfigModel model;

LSM9DS1_Accelerometer acc = LSM9DS1_Accelerometer(IMU);
LSM9DS1_Gyroscope gyro = LSM9DS1_Gyroscope(IMU);
LSM9DS1_Magnetometer mag = LSM9DS1_Magnetometer(IMU);

void setup() {
	Serial.begin(9600);

	while (!Serial);
	Serial.println("Started");

	if (!IMU.begin()) {
		Serial.println("Failed to initialize IMU!");
		while (1);
	}
}

void loop() {
	delay(500);

	int x, y, z;

	acc.getXYZ(x, y, z);
	String output = "X: " + String(x) + " Y: " + String(y) + " Z: " + String(z);
	Serial.println("Accelerometer Data:");
	Serial.println(output);

	gyro.getXYZ(x, y, z);
	output = "X: " + String(x) + " Y: " + String(y) + " Z: " + String(z);
	Serial.println("Gyroscope Data:");
	Serial.println(output);

	mag.getXYZ(x, y, z);
	output = "X: " + String(x) + " Y: " + String(y) + " Z: " + String(z);
	Serial.println("Magnetometer Data:");
	Serial.println(output);



	/*int xFlyingInput = model.FlyingInput.getX();
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

	model.MotorMixingAlgorithm.setMotorCorrections(rollCorrection, pitchCorrection, yawCorrection, altitudeCorrection, model.FlyingMotors);*/

}
