#pragma once
#include "pbullet.h"

Pbullet::Pbullet()
{
	timer = 0;

	vec2 hullVrts[] = { { -.1f, 0 },{ 0,.2f },{ .1f,0 } };
	Collider = collider(hullVrts, 3);
	transform.m_scale = vec2{ 40,40 };
	rigidbody.mass = 10;
}

void Pbullet::update(float deltaTime, Gamestate & gs)
{
	// The timer always counts down- if it dies, then we 
	// don't update or draw. If we don't do these things,
	// nobody even knows it exists.

	// When the bullet spawns, the timer can be set
	// along with a velocity and position (player update).
	timer -= deltaTime;
	isAlive = timer > 0;

	if (!isAlive) return;

	rigidbody.intergrate(transform, deltaTime);
}

void Pbullet::draw(const mat3 & camera)
{
	if (!isAlive) return;

	transform.debugDraw(camera);
	Collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
