#include "./../../headers/Hardware/URM09_UltrasonicSensor.h"

URM09_UltrasonicSensor::URM09_UltrasonicSensor(DFRobot_URM09& _sensor) : sensor(_sensor) {
	this->sensor.setModeRange(MEASURE_MODE_AUTOMATIC, MEASURE_RANG_150);
}
int URM09_UltrasonicSensor::getDistance() {
	return this->sensor.getDistance();
}