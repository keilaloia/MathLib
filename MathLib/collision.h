#pragma once
#include "vec2.0.h"
#include "shape.h"

struct CollisionData1D
{
	bool  result; // penetrationDepth > 0
	float penetrationDepth; // how much overlap
	float collisionNormal; // -1 or 1
	float MTV; // penetration depth * collision normal
};

CollisionData1D collisionDetection1D(float A_min, float A_max, float B_min, float B_max);

struct SweptCollisionData1D
{
	float entryTime, exitTime;
	float collisionNormal;

	bool result() const;
};

SweptCollisionData1D sweptDetection1D(float A_min, float A_max, float A_velocity,
									  float B_min, float B_max, float B_velocity);


struct CollisionData
{
	float penetrationDepth;
	vec2 collisionNormal;

	bool result() const;
	vec2 MTV() const;
};

CollisionData boxCollision(const AABB &A, const AABB &B);