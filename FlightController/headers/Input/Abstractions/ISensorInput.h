#ifndef SENSOR_INPIT_H
#define SENSOR_INPIT_H

class ISensorInput {
public:
	virtual int getAltitude();
	virtual int getYaw();
	virtual int getPitch();
	virtual int getRoll();
	virtual int getX();
	virtual int getY();
};

#endif