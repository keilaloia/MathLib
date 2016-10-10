#include"sfwdraw.h"
#include "vec2.0.h"
#include "Transform.h"
#include "flops.h"
#include <iostream>
#include "Rigidbody.h"
#include "spaceshiplocomotion.h"
#include "SpaceshipControllerh.h"
int main()
{
	// transform represents position
	// rigidbody represents moving(physical state)
	// locomotion represents movement
	//spacecontroller is controls

	sfw::initContext(800,800);
	


	SpaceshipController spacectrl('W', 'S', 'A', 'D',' ');



	Transform playerTransform{ 400, 200 };

	

	RigidBody playerRigidbody;
	
	SpaceshipLocomotion playerLoco;
	playerRigidbody.velocity = vec2{ 0,0 };

	vec2 basis = { 40, 0 };
	
	float ang_vec = 0;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();	
		playerTransform.debugDraw(); 

		
		spacectrl.update(playerLoco);

	

	playerLoco.update(playerTransform, playerRigidbody, deltaTime);
	playerRigidbody.intergrate(playerTransform, deltaTime);
	


	
		if (playerTransform.position.x < 0) playerTransform.position.x = 800;
		else if (playerTransform.position.x > 800) playerTransform.position.x = 0;
		if (playerTransform.position.y < 0) playerTransform.position.y = 800;
		else if (playerTransform.position.y > 800) playerTransform.position.y = 0;

		




	}


	sfw::termContext();
}


