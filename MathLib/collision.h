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

struct CollisionDataSwept
{
	float entryTime, exitTime;
	vec2 collisionNormal;

	bool result() const;
};

CollisionDataSwept boxCollisionSwept(const AABB &A, const vec2 &dA,
								const AABB &B, const vec2 &dB);

CollisionData planeBoxCollision(const Plane &P, const AABB & B);

CollisionDataSwept planeBoxCollisionSwept (const Plane &p, const AABB &b, const vec2 &bvel);

CollisionData HullCollision(const Hull &A, const Hull &B);

CollisionData HullCollisionGroups(const Hull  A[], unsigned asize, const Hull B[], unsigned bsize);
