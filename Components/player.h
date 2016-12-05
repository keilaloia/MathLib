#pragma once
#include "Transform.h"
#include "collider.h"
#include "Rigidbody.h"
#include "SpaceshipControllerh.h"
#include "spaceshiplocomotion.h"
#include "health.h"

class Playership
{
public:
	Transform transform;
	collider Collider;
	RigidBody Rigidbody;
	SpaceshipController controller;
	SpaceshipLocomotion locomotion;
	Health health;

	float firingTimer;

	Playership();

	void update(float deltaTime, class Gamestate &gs);
	void draw(const mat3 &camera);
};