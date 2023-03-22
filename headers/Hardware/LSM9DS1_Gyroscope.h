#ifndef LSM9DS1_GYROSCOPE_H
#define LSM9DS1_GYROSCOPE_H

#include "Abstractions/I3DSpaceSensor.h"
#include <Arduino_LSM9DS1.h>

class LSM9DS1_Gyroscope : public I3DSpaceSensor {
public:
	LSM9DS1_Gyroscope(LSM9DS1Class& imu);
	void getXYZ(int& x, int& y, int& z);
private:
	LSM9DS1Class& IMU;
};

#endif
