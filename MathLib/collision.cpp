#include "collision.h"

CollisionData1D collisionDetection1D(float A_min, float A_max, float B_min, float B_max)
{
	CollisionData1D retval;
	//retval.penetrationDepth
	float P = (B_max - A_min);
	float T = (A_max - B_min);
	float value;
	//retval.collisionNormal  = (A_max - B_min, B_max - A_min);
	//retval.penetrationDepth = (A_max - B_min) - (B_max - A_min);

	if (P > T)
	{
		value = T;
		retval.collisionNormal = -1;
	}
	else
	{
		value = P;
		 retval.collisionNormal = 1;

	}

	retval.penetrationDepth = value;
	retval.result = retval.penetrationDepth >= 0;
	retval.MTV = retval.penetrationDepth * retval.collisionNormal;
	return retval;
}
