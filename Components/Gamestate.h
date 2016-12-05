#pragma once
#include "player.h"
#include "camera.h"
#include "Asteroid.h"
#include "Parent.h"
#include "Gravbullet.h"
#include "objectCollision.h"
#include "Rigidbody.h"
#include "Invisbar.h"
#include "pbullet.h"
#include <iostream>


class Gamestate
{
	const unsigned BOSS_COUNT = 20;

public:

	Playership player;
	Camera camera;
	Asteroid asteroid[2];
	Parent parent[20];
	RigidBody rigidbody;
	GravBullet bullet[100];
	Invisbar invisbar[2];
	Pbullet playerBullet[100];

	void spawnBullet(const Transform &t, float impulse, bool playerOwned = false);
	void playerspawnBullet(const Transform &t, float impulse);


	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);


	void resetParent();


	void init();
	void update(float deltaTime);
	void draw();
};