#pragma once
#include "spaceshiplocomotion.h"

class SpaceshipController
{
public:
	unsigned keyup, keydown, keyLeft, keyright, keystop;

	SpaceshipController(int keyup, int Keydown, int Keyleft, int Keyright, int stop);


	void update(SpaceshipLocomotion &loco);
};