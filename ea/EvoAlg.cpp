#include "EvoAlg.h"
#include <math.h>

float EvoAlg::calculateDistance(float firstX, float firstY, float secondX, float secondY)
{
	float fullDistance, xDistance, yDistance;
	xDistance = secondX - firstX;
	yDistance = secondY - firstY;
	xDistance = xDistance * xDistance;
	yDistance = yDistance * yDistance;
	fullDistance = xDistance + yDistance;
	fullDistance = sqrt(fullDistance);
	return fullDistance;
}
