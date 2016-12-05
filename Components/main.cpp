#include"sfwdraw.h"
#include "vec2.0.h"
#include "Transform.h"
#include "flops.h"
#include <iostream>
#include "Rigidbody.h"
#include "spaceshiplocomotion.h"
#include "SpaceshipControllerh.h"
#include "PlanetaryMotor.h"
#include "spaceshiprender.h"
#include "collider.h"
#include "Gamestate.h"
#include "player.h"
int main()
{


	 float SCREEN_WIDTH = 1000, SCREEN_HEIGHT = 1000;
	 sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);

	 Gamestate game;
	 game.init();

	 while (sfw::stepContext())
	 {
		 float dt = sfw::getDeltaTime();
		 game.update(dt);
		 game.draw();



		

	}

	sfw::termContext();
}


