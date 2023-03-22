#include "../../headers/Hardware/LSM9DS1_Accelerometer.h"

LSM9DS1_Accelerometer::LSM9DS1_Accelerometer(BoschSensorClass& imu) : IMU(imu) {
}

void LSM9DS1_Accelerometer::getXYZ(int& x, int& y, int& z) {
	float _x, _y, _z;
	this->IMU.readAcceleration(_x, _y, _z);

	x = (int)_x;
	y = (int)_y;
	z = (int)_z;
}