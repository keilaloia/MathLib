#pragma once
#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"

class Parent
{
public:
	Transform			transform;
	collider			Collider;
	RigidBody			rigidbody;


	Parent();

	void update(float deltaTime, class Gamestate &gs);
	void draw(const mat3 &camera);
};