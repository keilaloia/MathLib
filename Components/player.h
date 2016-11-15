#pragma once
#include "Transform.h"
#include "collider.h"
#include"Rigidbody.h"
#include "SpaceshipControllerh.h"
#include "spaceshiplocomotion.h"

class Playership
{
public:
	Transform transform;
	collider Collider;
	RigidBody Rigidbody;
	SpaceshipController controller;
	SpaceshipLocomotion locomotion;

	Playership();

	void update(float deltaTime, class Gamestate &gs);
	void draw(const mat3 &camera);
};