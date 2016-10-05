#include "Rigidbody.h"

RigidBody::RigidBody()
{
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAcceleration = 0.0f;

}

void RigidBody::intergrate(Transform &trans, float deltaTime)
{
	velocity += acceleration * deltaTime;
	angularVelocity = angularVelocity + angularAcceleration * deltaTime;

	trans.position = trans.position + velocity * deltaTime;
	 
	trans.facing = trans.facing + angularVelocity * deltaTime;
}

void RigidBody::addForce(const vec2 &force)
{
	acceleration += force;
}

void RigidBody::addImpulse(const vec2 &impulse)
{
	velocity += impulse;
}

void RigidBody :: addTorque(float Torque)
{
	angularAcceleration += Torque;
}