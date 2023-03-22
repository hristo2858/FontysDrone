#ifndef LSM9DS1_GYROSCOPE_H
#define LSM9DS1_GYROSCOPE_H

#include <Arduino_BMI270_BMM150.h>
#include "Abstractions/I3DSpaceSensor.h"

class LSM9DS1_Gyroscope : public I3DSpaceSensor {
public:
	LSM9DS1_Gyroscope(BoschSensorClass& imu);
	void getXYZ(int& x, int& y, int& z);
private:
	BoschSensorClass& IMU;
};

#endif
