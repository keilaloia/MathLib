#include "Invisbar.h"


Invisbar::Invisbar()
{
	vec2 hullverts[] = { { -2, 6 },{ 0,6 },{ 0, -6 },{ -2,-6 } };
	Collider = collider(hullverts, 4);

	rigidbody.mass = 5000;
	transform.m_scale = vec2{ 4,4 };

}

void Invisbar::update(float deltaTime, Gamestate & gs)
{
	rigidbody.intergrate(transform, deltaTime);
}

void Invisbar::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	Collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
