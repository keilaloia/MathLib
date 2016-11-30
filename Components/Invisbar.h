#pragma once
#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "sfwdraw.h"

class Invisbar
{
public:
	Transform			transform;
	collider			Collider;
	RigidBody			rigidbody;

	Invisbar();

	void update(float deltaTime, class Gamestate &gs);
	void draw(const mat3 &camera);
};
