#include "ControlSystem/SimpleFeedbackErrorHandler.h"

float SimpleFeedbackErrorHandler::getError(int actual, int expected) {
	return actual - expected;
}