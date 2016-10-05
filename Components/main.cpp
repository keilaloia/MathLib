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

	sfw::initContext(800,800);

	//Transform p1(400, 300,KEY_LEFT_SHIFT, 'W', 'S', 'A', 'D');
	Transform playerTransform(400, 300,KEY_LEFT_SHIFT, 'W', 'S', 'A', 'D');

	playerTransform.facing = 0;
	playerTransform.scale = vec2{ 80,20 };


	/*vec2 start = { 200,200 },
		end = { 200,600 },
		mid = { 600,200 };*/

	RigidBody playerRigidbody;
	
	SpaceshipLocomotion playerLoco;
	SpaceshipController spacectrl;
	playerRigidbody.velocity = vec2{ 0,0 };

	vec2 basis = { 40, 0 };
	
	float ang_vec = 0;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		playerTransform .facing += sfw::getDeltaTime();
		playerTransform.debugDraw(); 
		playerLoco.update(playerRigidbody, deltaTime);
		spacectrl.update(playerLoco);

	/*	if (sfw::getKey('W'))
		{

			playerRigidbody.acceleration.y += 30.0f;
		}
		if (sfw::getKey('S'))
		{
			playerRigidbody.acceleration.y -= 30.0f;

		}
		if (sfw::getKey('A'))
		{
			playerRigidbody.acceleration.x -= 30.0f;

		}
		if (sfw::getKey('D'))
		{
			playerRigidbody.acceleration.x += 30.0f;

		}

		if (sfw::getKey('Q'))
		{
			playerRigidbody.angularAcceleration += 1.0f;

		}
		if (sfw::getKey('E'))
		{
			playerRigidbody.angularAcceleration -= 1.0f;

		}*/


	
		if (playerTransform.position.x < 0) playerTransform.position.x = 800;
		else if (playerTransform.position.x > 800) playerTransform.position.x = 0;
		if (playerTransform.position.y < 0) playerTransform.position.y = 800;
		else if (playerTransform.position.y > 800) playerTransform.position.y = 0;

		


		playerRigidbody.intergrate(playerTransform, deltaTime);



	}


	sfw::termContext();
}


//ang_vec += sfw::getDeltaTime();
//vec2 incident = fromAngle(ang_vec) * 40;
//float proj = dot(basis, normal(incident));

//sfw::drawLine(400, 300, 400 + basis.x, 300 + basis.y, RED);

//sfw::drawLine(400,300, 400 + incident.x, 300 + incident.y, CYAN);
//sfw::drawLine(400, 300, 400 + proj, 300, GREEN);

//vec2 start = { 100,100 },
//	end = { 200,600 },
//	mid = { 600,200 },
//	e_tan = { 200, 0 },
//	s_tan = { 400, 200 };


//for (int i = 0; i < 100; ++i)
//{
//	float t1 = i / 100.f; // 0-1 range
//	//float y1 = catRomSpline(.75, .25, 1, x1);

//	float t2 = (i + 1) / 100.f;
//	//float y2 = catRomSpline(.75, .25, 1, x2);

//	//x1 *= 800;
//	//x2 *= 800;
//	//y1 *= 800;
//	//y2 *= 800;

//	vec2 v1 = cardinalSpline(start, mid, end,5, t1);
//	vec2 v2 = cardinalSpline(start, mid, end,5, t2);

//	sfw::drawLine(v1.x, v1.y, v2.x, v2.y);