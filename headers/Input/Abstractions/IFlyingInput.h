#ifndef FLYING_INPUT_H
#define FLYING_INPUT_H

class IFlyingInput {
	public:
		virtual int getX();
		virtual int getY();
		virtual int getZ();
		virtual int getYaw();
		virtual int getEstimationYaw();
};

#endif