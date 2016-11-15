#pragma once
#include "player.h"
#include "camera.h"

class Gamestate
{
public:
	Playership player;
	Camera camera;

	void init();
	void update(float deltaTime);
	void draw();
};