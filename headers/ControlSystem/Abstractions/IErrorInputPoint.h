#ifndef FEEDBACK_ERROR_HANDLER_H
#define FEEDBACK_ERROR_HANDLER_H

class IErrorInputPoint {
public:
	virtual int getError(int actual, int expected);
};

#endif