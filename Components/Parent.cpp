#include "Parent.h"
#include "Gamestate.h"
#include <cmath>
Parent::Parent()
{
	vec2 hullverts[] = { {-2, 0}, {0,3},{2, 0}, {0,-3} };
	Collider = collider(hullverts, 4);

	transform.m_scale = vec2{ 4,4 };

	rigidbody.drag = 0;
	maxspeed = 30.0;
	turnspeed = 5.0;
	startspeed = 0.2;
	forcepower = { 100,0 };

	firingTimer = 0;

	

}


void Parent::update(float deltaTime, Gamestate & gs)
{
	rigidbody.intergrate(transform, deltaTime);

	turnspeed += deltaTime * 1;

	firingTimer -= deltaTime;

	//don't spawn if dead
	if (health.isAlive == false)
	{
		return;

	}
	//parent losing health
	if (health.health <= 0)
	{
		health.isAlive = false;
		gs.parent[0].health.health -= 10;
	}

	//turning

	if (turnspeed >= maxspeed)
	{
		turnspeed = maxspeed;
	}

	for (int i = 0; i < 20; i++)
	{
		gs.parent[i].rigidbody.addTorque(startspeed * turnspeed);
	}

	// bullet
	if (health.isAlive == true && firingTimer < 0)
	{
		gs.spawnBullet(transform, 100);
		firingTimer = 0.50f;
	}

	
}

void Parent::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	Collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
	health.debugDraw(camera, transform);
}
