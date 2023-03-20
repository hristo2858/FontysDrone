#ifndef WORLD_TO_BODY_CONVERTER_H
#define WORLD_TO_BODY_CONVERTER_H

class IWorldToBodyConverter {
	public:
		virtual float getWorldToBodyRollCorrection(int yawEstimation, int xExpected, int yExpected, int xActual, int yActual);
		virtual float getWorldToBodyPitchCorrection(int yawEstimation, int xExpected, int yExpected, int xActual, int yActual);
};

#endif