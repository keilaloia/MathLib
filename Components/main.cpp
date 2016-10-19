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
int main()
{
	// transform represents m_position
	// rigidbody represents moving(physical state)
	// locomotion represents movement
	//spacecontroller is controls

	sfw::initContext(800,800);
	


	SpaceshipController spacectrl('W', 'S', 'D', 'A',' ');
	

	//SpaceshipController First(' ',' ', KEY_RIGHT, KEY_LEFT, ' ');

	//SpaceshipController Second(' ', ' ', '1', '2', ' ');

	//SpaceshipController Third(' ', ' ', 'Z', 'X', ' ');


	Transform playerTransform{ 400, 200 };
	//Transform ST1(50, 0);
	//Transform ST2(50, 0);
	//Transform ST3(50, 0);
	//
	RigidBody playerRigidbody;
	//RigidBody FirstRigidbody;
	//RigidBody SecondRigidbody;
	//RigidBody ThirdRigidbody;


	//ST1.m_parent = &playerTransform;
	//ST2.m_parent = &ST1;
	//ST3.m_parent = &ST2;

	////ST2.m_parent = &playerTransform;
	////ST3.m_parent = &playerTransform;

	//
	SpaceshipLocomotion playerLoco;
	//SpaceshipLocomotion FirstLoco;
	//SpaceshipLocomotion SecondLoco;
	//SpaceshipLocomotion ThirdLoco;


	////FirstLoco.speed = 100;
	//
	playerRigidbody.velocity = vec2{ 0,0 };
	//FirstRigidbody.velocity = vec2{ 0,0 };
	//SecondRigidbody.velocity = vec2{ 0,0 };
	//ThirdRigidbody.velocity = vec2{ 0,0 };


	//SpaceshipController Sunc(' ', ' ', 'Z', 'X', ' ');

	Transform cameraTransform;
	Transform SunTransform{ 400,200 };
	Transform MercuryTransform{ 30,0 };
	Transform VenusTransform{ 60,20 };
	vec2 CameraPosition = vec2{ 0,0 };


	RigidBody SunRigidbody;
	RigidBody MercuryRigidbody;
	RigidBody VenusRigidbody;
	//SpaceshipLocomotion MercuryLoco;
	//SpaceshipLocomotion SunLoco;

	PlanetaryMotor Sunmotor;
	PlanetaryMotor Mercurymotor;
	PlanetaryMotor Venusmotor;

	ShipRender  ship1;
	


	


	Sunmotor.m_rotationspeed = 1;
	Mercurymotor.m_rotationspeed = 2;
	Venusmotor.m_rotationspeed = .120;

	MercuryTransform.m_parent = &SunTransform;
	VenusTransform.m_parent = &SunTransform;
	vec2 basis = { 40, 0 };
	
	float ang_vec = 0;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();
		
		cameraTransform.m_position = lerp(cameraTransform.m_position,
									      playerTransform.getGlobalPosition(),// + SunTransform.getGlobalPosition() / 2, 
									      1.f);

	
		mat3 proj = translate(400, 400) * scale(2, 2);
		mat3 view = inverse(cameraTransform.getGlobalTransform());
		mat3 camera = proj * view;

		////intergrate helps it accelerate i think or rigid body does idk :(
		playerRigidbody.intergrate(playerTransform, deltaTime);

		
		//find the location playerloco= location
		spacectrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody, deltaTime);
		
		

		//FirstRigidbody.intergrate(ST1, deltaTime);
		//ST1.debugDraw();
		//First.update(FirstLoco);
		//FirstLoco.update(ST1, FirstRigidbody, deltaTime);

		//SecondRigidbody.intergrate(ST2, deltaTime);
		//ST2.debugDraw();
		//Second.update(SecondLoco);
		//SecondLoco.update(ST2, SecondRigidbody, deltaTime);


		//ThirdRigidbody.intergrate(ST3, deltaTime);
		//ST3.debugDraw();
		//Third.update(ThirdLoco);
		//ThirdLoco.update(ST3, ThirdRigidbody, deltaTime);


		//SunLoco.update(MercuryTransform, MercuryRigidbody, deltaTime);
		Sunmotor.update(SunRigidbody);
		SunRigidbody.intergrate(SunTransform, deltaTime);
		SunTransform.debugDraw(camera);


		//MercuryLoco.update(MercuryTransform, MercuryRigidbody, deltaTime);
		Mercurymotor.update(MercuryRigidbody);
		MercuryRigidbody.intergrate(MercuryTransform, deltaTime);
		MercuryTransform.debugDraw(camera);


		Venusmotor.update(VenusRigidbody);
		VenusRigidbody.intergrate(VenusTransform, deltaTime);
		VenusTransform.debugDraw(camera);

		//playerRigidbody.debugDraw(playerTransform);	// TODO: add camera matrix
		playerTransform.debugDraw(camera);

		ship1.drawship(playerTransform, camera);
		

	
		//global position
		//vec2 tpos = playerTransform.getGlobalPosition();

		if (playerTransform.m_position.x < 0) playerTransform.m_position.x = 800;
		else if (playerTransform.m_position.x > 800) playerTransform.m_position.x = 0;
		if (playerTransform.m_position.y < 0) playerTransform.m_position.y = 800;
		else if (playerTransform.m_position.y > 800) playerTransform.m_position.y = 0;

	



	}


	sfw::termContext();
}


