#pragma once



#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"

class Asteroid
{
public:
	Transform			transform;
	collider			Collider;
	RigidBody			rigidbody;
	//bool isAlive;

	Asteroid();

	void update(float deltaTime, class Gamestate &gs);
	void draw(const mat3 &camera);
};