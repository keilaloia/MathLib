#pragma once
#include "spaceshiplocomotion.h"

class SpaceshipController
{
public:
	unsigned keyup, keydown, keyLeft, keyright, keystop;

	SpaceshipController(
		//int keyup='W', 
		//int Keydown='S', 
		int Keyleft='A', 
		int Keyright='D', 
		int stop=' ');

	

	void update(SpaceshipLocomotion &loco);
};