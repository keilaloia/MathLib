#pragma once
#include "vec2.0.h"


class Transform
{
public:

	Transform();
	Transform(float x, float y,int Sprint, int up , int down, int left , int right );
	vec2 position;
	vec2 scale;
	float facing;

	vec2 getDirection();
	void setDirection(const vec2 &dir);
	


	int Upkey;
	int Downkey;
	int rLeft;
	int rRight;
	int Sprint;

	void debugDraw();
};