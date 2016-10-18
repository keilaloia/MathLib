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
	// transform represents m_position
	// rigidbody represents moving(physical state)
	// locomotion represents movement
	//spacecontroller is controls

	sfw::initContext(800,800);
	


	SpaceshipController spacectrl('W', 'S', 'D', 'A',' ');

	SpaceshipController First(KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, ' ');

	SpaceshipController Second('1', '2', '3', '4', ' ');

	SpaceshipController Third('T', 'F', 'G', 'H', ' ');


	Transform playerTransform{ 400, 200 };
	Transform ST1(50, 0);
	Transform ST2(50, 0);
	Transform ST3(50, 0);
	
	RigidBody playerRigidbody;
	RigidBody FirstRigidbody;
	RigidBody SecondRigidbody;
	RigidBody ThirdRigidbody;


	ST1.m_parent = &playerTransform;
	ST2.m_parent = &ST1;
	ST3.m_parent = &ST2;

	//ST2.m_parent = &playerTransform;
	//ST3.m_parent = &playerTransform;

	
	SpaceshipLocomotion playerLoco;
	SpaceshipLocomotion FirstLoco;
	SpaceshipLocomotion SecondLoco;
	SpaceshipLocomotion ThirdLoco;


	//FirstLoco.speed = 100;
	
	playerRigidbody.velocity = vec2{ 0,0 };
	FirstRigidbody.velocity = vec2{ 0,0 };
	SecondRigidbody.velocity = vec2{ 0,0 };
	ThirdRigidbody.velocity = vec2{ 0,0 };



	vec2 basis = { 40, 0 };
	
	float ang_vec = 0;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();	
		//intergrate helps it accelerate i think or rigid body does idk :(
		playerRigidbody.intergrate(playerTransform, deltaTime);
		playerTransform.debugDraw(); 
		//find the location playerloco= location
		spacectrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody, deltaTime);
		playerRigidbody.debugDraw(playerTransform);
		

		FirstRigidbody.intergrate(ST1, deltaTime);
		ST1.debugDraw();
		First.update(FirstLoco);
		FirstLoco.update(ST1, FirstRigidbody, deltaTime);

		SecondRigidbody.intergrate(ST2, deltaTime);
		ST2.debugDraw();
		Second.update(SecondLoco);
		SecondLoco.update(ST2, SecondRigidbody, deltaTime);


		ThirdRigidbody.intergrate(ST3, deltaTime);
		ST3.debugDraw();
		Third.update(ThirdLoco);
		ThirdLoco.update(ST3, ThirdRigidbody, deltaTime);

	

	
		//global position
		vec2 tpos = playerTransform.getGlobalPosition();

		if (playerTransform.m_position.x < 0) playerTransform.m_position.x = 800;
		else if (playerTransform.m_position.x > 800) playerTransform.m_position.x = 0;
		if (playerTransform.m_position.y < 0) playerTransform.m_position.y = 800;
		else if (playerTransform.m_position.y > 800) playerTransform.m_position.y = 0;

	



	}


	sfw::termContext();
}


