#ifndef SIMPLE_FEEDBACK_ERROR_HANDLER_H
#define SIMPLE_FEEDBACK_ERROR_HANDLER_H

#include "Abstractions/IErrorInputPoint.h"

class ErrorInputPoint : public IErrorInputPoint {
public:
	int getError(int actual, int expected);
};

#endif