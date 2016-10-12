#pragma once
#include "vec2.0.h"
#include "Mat3.h"

class Transform
{
public:

	Transform();
	Transform(float x, float y);
	vec2 m_position/*{ 200,200 }*/;
	vec2 m_scale;
	float m_facing;
	vec2 playerVelocity = { 0, 0 };
	
	vec2 getDirection() const;
	void setDirection(const vec2 &dir);
	mat3 getLocalTransform() const;

	

	void debugDraw(const mat3 &T = mat3Identity())const;
};