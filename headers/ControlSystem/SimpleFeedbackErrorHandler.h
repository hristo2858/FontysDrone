#ifndef SIMPLE_FEEDBACK_ERROR_HANDLER_H
#define SIMPLE_FEEDBACK_ERROR_HANDLER_H

#include "Abstractions/IFeedbackErrorHandler.h"

class SimpleFeedbackErrorHandler : public IFeedbackErrorHandler {
public:
	float getError(int actual, int expected);
};

#endif