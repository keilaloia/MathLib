#pragma once
#include "vec2.0.h"

class Transform
{
public:

	Transform();
	Transform(float x, float y,int Sprint, int up , int down, int left , int right );
	vec2 position{ 200,200 };
	vec2 scale;
	float facing;
	vec2 playerVelocity = { 0, 0 };
	
	vec2 getDirection() const;
	void setDirection(const vec2 &dir);

	

	void debugDraw()const;
};