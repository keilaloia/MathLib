#pragma once

struct CollisionData1D
{
	bool  result; // penetrationDepth > 0
	float penetrationDepth; // how much overlap
	float collisionNormal; // -1 or 1
	float MTV; // penetration depth * collision normal
};

CollisionData1D collisionDetection1D(float A_min, float A_max, float B_min, float B_max);