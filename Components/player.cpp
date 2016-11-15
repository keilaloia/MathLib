#include "player.h"
#include "Gamestate.h"

Playership::Playership()
{
	vec2 Hullverts[] = { { 0,7 },{ -6, 0 },{ 6,0 },{ 0,-6 } };
	Collider = collider(Hullverts, 4);

	transform.m_scale = vec2{ 10,10 };
}

void Playership::update(float deltaTime, Gamestate & gs)
{
	controller.update(locomotion);
	locomotion.update(transform, Rigidbody, deltaTime);
	Rigidbody.intergrate(transform, deltaTime);
}

void Playership::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	Collider.DebugDraw(camera, transform);
	Rigidbody.debugDraw(camera, transform);
}
