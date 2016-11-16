#pragma once
#include "player.h"
#include "camera.h"
#include "Asteroid.h"
#include "Parent.h"
#include "Gravbullet.h"
#include "objectCollision.h"
#include "Rigidbody.h"


class Gamestate
{
	unsigned boss = 20;

public:

	Playership player;
	Camera camera;
	Asteroid asteroid[2];
	Parent parent[20];
	RigidBody rigidbody;
	GravBullet bullet;



	void init();
	void update(float deltaTime);
	void draw();
};