#include "../../headers/Hardware/LSM9DS1_Gyroscope.h"

LSM9DS1_Gyroscope::LSM9DS1_Gyroscope(LSM9DS1Class& imu) : IMU(imu) {
}

void LSM9DS1_Gyroscope::getXYZ(int& x, int& y, int& z) {
	float _x, _y, _z;
	this->IMU.readGyroscope(_x, _y, _z);

	x = (int)_x;
	y = (int)_y;
	z = (int)_z;
}