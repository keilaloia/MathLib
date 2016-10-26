#include "collision.h"
#include <cmath>
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
		retval.collisionNormal = 1;
	}
	else
	{
		value = P;
		 retval.collisionNormal = -1;

	}

	retval.penetrationDepth = value;
	retval.result = retval.penetrationDepth >= 0;
	retval.MTV = retval.penetrationDepth * retval.collisionNormal;
	return retval;
}

SweptCollisionData1D sweptDetection1D(float A_min, float A_max, float A_velocity, float B_min, float B_max, float B_velocity)
{
	SweptCollisionData1D retval;
	

	float tL = (A_min - B_max) / (B_velocity - A_velocity);
	float tR = (B_min - A_max) / (A_velocity - B_velocity);
	retval.collisionNormal = copysignf(1, tL - tR);

	
	if (tL > tR)
	{
		retval.exitTime = tL;
		retval.entryTime = tR;
	}
	else if (tR > tL)
	{
		retval.exitTime = tR;
		retval.exitTime = tL;
	}

	return retval;
}

bool SweptCollisionData1D::result() const
{
	return entryTime >= 0 && exitTime <= 1;
}

CollisionData boxCollision(const AABB & A, const AABB & B)
{
	CollisionData1D X = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);
	CollisionData1D Y = collisionDetection1D(A.min().y, A.max().y, B.min().y, B.max().y);

	CollisionData retval;
	if (X.penetrationDepth > Y.penetrationDepth)
	{
		retval.penetrationDepth = Y.penetrationDepth;
		retval.collisionNormal = vec2{ 0 , Y.collisionNormal };
	}
	else //if (x.penetrationDepth < y.penetrationDepth)
	{
		retval.penetrationDepth = X.penetrationDepth;
		retval.collisionNormal = vec2{ X.collisionNormal , 0 };

	}

	return retval;
}

bool CollisionData::result() const
{
	return penetrationDepth >= 0;

}

vec2 CollisionData::MTV() const
{
	return penetrationDepth * collisionNormal;
}
