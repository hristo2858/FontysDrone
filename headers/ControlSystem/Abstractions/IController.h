#ifndef CONTROLLER_H
#define CONTROLLER_H

class IController {
	public:
		virtual int getCorrection(int error);
};

#endif