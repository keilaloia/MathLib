#include "Parent.h"
#include <cmath>
Parent::Parent()
{
	vec2 hullverts[] = { {-2, 0}, {0,3},{2, 0}, {0,-3} };
	Collider = collider(hullverts, 4);

	transform.m_scale = vec2{ 2,2 };

	
}

void Parent::update(float deltaTime, Gamestate & gs)
{
	rigidbody.intergrate(transform, deltaTime);
}

void Parent::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	Collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
