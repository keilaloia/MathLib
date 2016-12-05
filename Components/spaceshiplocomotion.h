#pragma once
#include "Rigidbody.h"
#include "sfwdraw.h"

class SpaceshipLocomotion
{
	//float thrust;	//forward movement
	//float maxThrust; // max forward movement
	//float thrustSpeed; // rate of change for our thrust

	float horzThrust;// horizontal (-1 to 1 value)
	float breakpower;
	float stopAction;

	//float turn; //turn
	//float maxTurn; //max turn
	//float turnSpeed; //rate of change for our turn
	
	float maxSpeed;
public:
	float speed; //movement speed
	
	SpaceshipLocomotion();

	void doThrust(float value);

	void doStop(float value);
	void  update(const Transform &trans, RigidBody &rigidBody, float deltaTime);

};