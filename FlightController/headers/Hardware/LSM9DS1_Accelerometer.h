#ifndef LSM9DS1_ACCELEROMETER_H
#define LSM9DS1_ACCELEROMETER_H

#include <Arduino_BMI270_BMM150.h>
#include "Abstractions/I3DSpaceSensor.h"

class LSM9DS1_Accelerometer : public I3DSpaceSensor {
public:
	LSM9DS1_Accelerometer(BoschSensorClass& imu);
	void getXYZ(int& x, int& y, int& z);
private:
	BoschSensorClass& IMU;
};

#endif
