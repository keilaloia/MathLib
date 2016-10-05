#pragma once
#include "vec2.0.h"
#include "Transform.h"

class RigidBody
{
public: 
	RigidBody();
	vec2 velocity; // represents the change in position
	float angularVelocity; // represents the change in rotation
	void intergrate(Transform &trans, float deltaTime); // performs integrations
	vec2 acceleration;
	float angularAcceleration;
	
	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);
	void addTorque(float torque);

};