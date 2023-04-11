#ifndef CONTROLLER_H
#define CONTROLLER_H

class IController {
	public:
		virtual float getCorrection(float error);
};

#endif