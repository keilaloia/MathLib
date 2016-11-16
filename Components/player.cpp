#include "player.h"
#include "Gamestate.h"
#include <cmath>

Playership::Playership()
{
	vec2 Hullverts[] = { { 0,-7 },{ 10, 0 },{ 0,6 } };
	Collider = collider(Hullverts,3);

	transform.m_scale = vec2{ 10,10 };
	
}

void Playership::update(float deltaTime, Gamestate & gs)
{
	controller.update(locomotion);
	locomotion.update(transform, Rigidbody, deltaTime);
	Rigidbody.intergrate(transform, deltaTime);

	if (sfw::getKey('F') && !gs.bullet.isAlive)
	{
		// bring it to life
		gs.bullet.timer = 2.f;

		// set up it's position and stuff
		gs.bullet.transform.m_position = transform.m_position;
		gs.bullet.transform.m_facing = transform.m_facing;

		//reset velocity
		gs.bullet.rigidbody.velocity = vec2{ 0,0 };
		// get it moving
		gs.bullet.rigidbody.addImpulse(transform.getup() * 3000.f);
	}

}

void Playership::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	Collider.DebugDraw(camera, transform);
	Rigidbody.debugDraw(camera, transform);
}
