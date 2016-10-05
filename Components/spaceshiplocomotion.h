#pragma once
#include "Rigidbody.h"
#include "sfwdraw.h"

class SpaceshipLocomotion
{
	float thrust;	//forward movement
	float maxThrust; // max forward movement
	float thrustSpeed; // rate of change for our thrust

	float vertThrust;// vertical (-1 to 1 value)
	float horzThrust;// horizontal (-1 to 1 value)

	float turn; //turn
	float maxTurn; //max turn
	float turnSpeed; //rate of change for our turn

	float speed; //movement speed
	float maxSpeed;
public:
	SpaceshipLocomotion();

	void doThrust(float value);
	void doTurn(float value);

	

	void  update(RigidBody &rigidBody, float deltaTime);

};