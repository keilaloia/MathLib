#include "spaceshipLocomotion.h"
#include "Rigidbody.h"




SpaceshipLocomotion::SpaceshipLocomotion()
{
	//vertThrust = 0.0f;
	//maxThrust = 100.0f;
	//thrustSpeed = 1.0f;

	horzThrust = 0.0f;
	//maxTurn = 100.0f;
	//turnSpeed = 3.0f;

	breakpower = 10.0f;
	//breakpower = 0;
	//turnSpeed = 1.0f;
	speed = 50.0f;
	maxSpeed = 50.0f;
	stopAction = 0;
}

//
void SpaceshipLocomotion::doThrust(float value)
{
	horzThrust += value;
}

void SpaceshipLocomotion::doStop(float value)
{
	stopAction += value;
}

void SpaceshipLocomotion::update(const Transform &trans, RigidBody &rigidbody, float deltaTime)
{
	// thrusting
	rigidbody.addForce(trans.getGlobalUp() * speed * horzThrust);

	// stopping
	float currentSpeed = magnitude(rigidbody.velocity);
	rigidbody.addForce(-rigidbody.velocity * breakpower * stopAction);
	
	horzThrust = stopAction = 0;
}