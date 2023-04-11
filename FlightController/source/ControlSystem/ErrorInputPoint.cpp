#include "./../../headers/ControlSystem/ErrorInputPoint.h"

int ErrorInputPoint::getError(int actual, int expected) {
	return actual - expected;
}