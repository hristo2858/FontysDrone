#ifndef THREE_D_Space_Sensor_H
#define THREE_D_Space_Sensor_H

class I3DSpaceSensor {
public:
	virtual void getXYZ(int& x, int& y, int& z);
};

#endif