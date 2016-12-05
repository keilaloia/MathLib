#include "player.h"
#include "Gamestate.h"
#include <cmath>

Playership::Playership()
{
	vec2 Hullverts[] = { { 0,-7 },{ 10, 0 },{ 0,6 } };
	Collider = collider(Hullverts,3);

	firingTimer = 0;
	transform.m_scale = vec2{ 10,10 };
	
}

void Playership::update(float deltaTime, Gamestate & gs)
{
	controller.update(locomotion);
	locomotion.update(transform, Rigidbody, deltaTime);
	Rigidbody.intergrate(transform, deltaTime);


	firingTimer -= deltaTime;

	if (sfw::getKey('F') && firingTimer < 0)
	{
		gs.playerspawnBullet(transform, 100);
		firingTimer = 0.25f;
	}

}

void Playership::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	Collider.DebugDraw(camera, transform);
	Rigidbody.debugDraw(camera, transform);
	health.debugDraw(camera, transform);

}


//for loops in cpp, collision, player cpp, gamestate
