#include "SpaceshipControllerh.h"

SpaceshipController::SpaceshipController(
	//int up, 
	//int down, 
	int left, 
	int right, 
	int stop)
{
	//keyup = up;
	//keydown = down;
	keyLeft = left;
	keyright = right;
	keystop = stop;
	
}


void SpaceshipController::update(SpaceshipLocomotion & loco)
{
	float horizontalInput = 0.0f;
	horizontalInput += sfw::getKey(keyLeft);
	horizontalInput -= sfw::getKey(keyright);

	float bInput = sfw::getKey(keystop);

	loco.doThrust(horizontalInput);
	loco.doStop(bInput);
}
