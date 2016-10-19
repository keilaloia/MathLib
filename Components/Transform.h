#pragma once
#include "vec2.0.h"
#include "Mat3.h"

class Transform
{
public:

	//Transform();
	Transform * m_parent;
	Transform(float x, float y);
	Transform();
	vec2 m_position/*{ 200,200 }*/;
	vec2 m_scale;
	float m_facing;
	vec2 playerVelocity = { 0, 0 };
	
	vec2 getup() const;
	vec2 getDirection() const;
	void setDirection(const vec2 &dir);
	mat3 getLocalTransform() const;
	mat3 getGlobalTransform() const;
	
	float getGlobalAngle() const;
	vec2 getGlobalRight() const;
	vec2 getGlobalUp() const;
	vec2 getGlobalPosition()const;

	void debugDraw(const mat3 &T = mat3Identity())const;
};