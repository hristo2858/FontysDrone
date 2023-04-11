#ifndef MOTOR_H
#define MOTOR_H

class IMotor{

	public:
		virtual void setPWMSignal(int value);
};

#endif