#include <Arduino_BMI270_BMM150.h>
#include <DFRobot_URM09.h>

#include "models/DroneConfigModel.h"
#include "headers/Hardware/LSM9DS1_Accelerometer.h"
#include "headers/Hardware/LSM9DS1_Gyroscope.h"
#include "headers/Hardware/LSM9DS1_Magnetometer.h"

//DroneConfigModel model;

LSM9DS1_Accelerometer acc = LSM9DS1_Accelerometer(IMU);
LSM9DS1_Gyroscope gyro = LSM9DS1_Gyroscope(IMU);
LSM9DS1_Magnetometer mag = LSM9DS1_Magnetometer(IMU);

DFRobot_URM09 URM09;

void setup() {
	Serial.begin(9600);

	while (!Serial);
	Serial.println("Started");

	if (!IMU.begin()) {
		Serial.println("Failed to initialize IMU!");
		while (1);
	}

	/**
	* I2c device number 1-127
	* When the i2c device number is not passed, the default parameter is 0x11
	*/
	/*while (!URM09.begin()) {
		Serial.println("I2c device number error");
		delay(1000);
	}*/
}

void loop() {
	delay(1500);

	int x, y, z;

	acc.getXYZ(x, y, z);
	String output = "X: " + String(x) + " Y: " + String(y) + " Z: " + String(z);
	Serial.println(output);

	float _x, _y, _z;
	IMU.readAcceleration(_x, _y, _z);

	output = "X: " + String(_x) + " Y: " + String(_y) + " Z: " + String(_z);
	Serial.println(output);

	/*gyro.getXYZ(x, y, z);
	output = "X: " + String(x) + " Y: " + String(y) + " Z: " + String(z);
	Serial.println("Gyroscope Data:");
	Serial.println(output);

	mag.getXYZ(x, y, z);
	output = "X: " + String(x) + " Y: " + String(y) + " Z: " + String(z);
	Serial.println("Magnetometer Data:");
	Serial.println(output);*/



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
