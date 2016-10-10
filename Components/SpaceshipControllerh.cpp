#include "SpaceshipControllerh.h"

SpaceshipController::SpaceshipController(int up, int down, int left, int right, int stop)
{
	keyup = up;
	keydown = down;
	keyLeft = left;
	keyright = right;
	keystop = stop;
	
}


void SpaceshipController::update(SpaceshipLocomotion & loco)
{
	float hInput = 0.0f;
	hInput -= sfw::getKey(keyLeft);
	hInput += sfw::getKey(keyright);

	float vInput = 0.0f;

	vInput -= sfw::getKey(keydown);
	vInput += sfw::getKey(keyup);

	float bInput = sfw::getKey(keystop);



	loco.doTurn(hInput);
	loco.doThrust(vInput);
	loco.doStop(bInput);


}
