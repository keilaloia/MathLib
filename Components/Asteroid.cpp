#include "Asteroid.h"

Asteroid::Asteroid()
{
	vec2 hullVrts[] = { { -1, 0 },{ 0,1 },{ 1,0 } };
	Collider = collider(hullVrts, 3);

	transform.m_scale = vec2{ 12,12 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 10;



}

void Asteroid::update(float deltaTime, Gamestate & gs)
{
	rigidbody.intergrate(transform, deltaTime);
}

void Asteroid::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	Collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}