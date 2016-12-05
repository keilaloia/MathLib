#pragma once
#include "vec2.0.h"
#include "Transform.h"
#include "sfwdraw.h"
#include "Rigidbody.h"

class Health
{
public:
	float health;
	float maxHealth;
	bool isAlive;
	float visualWidth;

	Health();

	void debugDraw(const mat3& T, const Transform & trans);
};
