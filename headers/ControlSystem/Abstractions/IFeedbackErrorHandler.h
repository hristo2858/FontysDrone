#ifndef FEEDBACK_ERROR_HANDLER_H
#define FEEDBACK_ERROR_HANDLER_H

class IFeedbackErrorHandler {
public:
	virtual float getError(int actual, int expected);
};

#endif