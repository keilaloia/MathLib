#pragma once
#include "Rigidbody.h"

class PlanetaryMotor
{

public:
	
	float m_rotationspeed;
	
	void update(RigidBody &planetRbody);
};