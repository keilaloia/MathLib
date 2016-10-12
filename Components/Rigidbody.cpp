#include "Rigidbody.h"

RigidBody::RigidBody()
{
	mass = 1;
	force = vec2{ 0,0 };
	impulse = vec2{ 0,0 };
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAcceleration = 0.0f;
	torque = 0;
	drag = .25;
	angularDrag = 1;
}

void RigidBody::addForce(const vec2 &a_force)
{
	force += a_force;
}

void RigidBody::addImpulse(const vec2 &a_impulse)
{
	impulse += a_impulse;
}

void RigidBody :: addTorque(float a_Torque)
{
	// acceleration is = force/mass
	torque += a_Torque;
}

void RigidBody::debugDraw(const Transform & trans)
{
	vec2 p = trans.m_position;
	vec2 v = p + velocity;
	vec2 a = acceleration + v;
	sfw::drawLine(p.x, p.y, v.x, v.y, CYAN);
	sfw::drawLine(p.x, p.y, a.x, a.y, MAGENTA);
}

void RigidBody::intergrate(Transform &trans, float deltaTime)
{

	acceleration = force / mass;
	
	velocity	   += acceleration * deltaTime + impulse / mass;
	trans.m_position += velocity * deltaTime;
	force = impulse = { 0,0 };
	//Dampening force
	force = -velocity * drag;

	angularAcceleration = torque / mass;
	angularVelocity		+= angularAcceleration * deltaTime;
	trans.m_facing		+= angularVelocity * deltaTime;
	torque = 0;
	torque = -angularVelocity * angularDrag;
}