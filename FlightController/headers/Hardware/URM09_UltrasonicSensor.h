#ifndef URM09_ULTRASONIC_SENSOR_H
#define URM09_ULTRASONIC_SENSOR_H

#include <DFRobot_URM09.h>
#include "Abstractions/IDistanceSensor.h"

class URM09_UltrasonicSensor : public IDistanceSensor {
public:
	URM09_UltrasonicSensor(DFRobot_URM09& _sensor);
	int getDistance();
private:
	DFRobot_URM09& sensor;
};

#endif
