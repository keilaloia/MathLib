#pragma once
#include "vec2.0.h"
#include "Transform.h"
#include "sfwdraw.h"

class RigidBody
{
public: 
	RigidBody();

	float mass, drag;
	float angularDrag;
	float torque;
	float angularVelocity; // represents the change in rotation
	float angularAcceleration;

	vec2 force, impulse;
	vec2 velocity;// represents the change in position
	vec2 acceleration;


	void intergrate(Transform &trans, float deltaTime); // performs integrations
	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);
	void addTorque(float torque);
	void debugDraw(const Transform &trans);
};