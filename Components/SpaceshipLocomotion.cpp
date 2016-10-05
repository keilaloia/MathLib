#include "spaceshipLocomotion.h"
#include "Rigidbody.h"




SpaceshipLocomotion::SpaceshipLocomotion()
{
	vertThrust = 0.0f;
	maxThrust = 100.0f;
	thrustSpeed = 1.0f;

	horzThrust = 0.0f;
	maxTurn = 100.0f;
	turnSpeed = 3.0f;

	speed = 150.0f;
	maxSpeed = 1000.0f;
}

//
void SpaceshipLocomotion::doThrust(float value)
{
	vertThrust = value;

	//if (sfw::getKey('W')) vertThrust += 1.f;
	//if (sfw::getKey('S')) vertThrust -= 1.f;

	

	

}

void SpaceshipLocomotion::doTurn(float value)
{
	horzThrust = value;
	//if (sfw::getKey('D')) horzThrust += 1;
	//if (sfw::getKey('A')) horzThrust -= 1;

}

void SpaceshipLocomotion::update(RigidBody &rigidbody, float deltaTime)
{



	rigidbody.acceleration.x = horzThrust * speed;
	rigidbody.acceleration.y = vertThrust * speed;


	//if we are moving faster than our max speed
	if (magnitude(rigidbody.velocity) > maxSpeed)
	{
		//gets the direction
		vec2 dir = normal(rigidbody.velocity);

		//keeps it at max speed
		rigidbody.velocity = dir * maxSpeed;
	}


	//vertThrust = 0.0f;
	//horzThrust = 0.0f;
}