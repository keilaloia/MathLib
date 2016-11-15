#pragma once
#include "shape.h"
#include "Transform.h"
#include "collision.h"
#include "Rigidbody.h"
class collider
{
public:
	AABB box;
	Hull hull;

	collider(const vec2 * verts, int size);

	void DebugDraw(const mat3 &T, const Transform &trans);
};

CollisionData ColliderCollision(const Transform &AT,
								const Transform &BT,
								const collider &AC,
								const collider &BC);


CollisionData StaticCollision(Transform &AT, RigidBody &AR, const collider &AC,
							  const Transform &BT, const collider &BC,
							  float bounciness);


CollisionData DynamicCollision(Transform &AT, RigidBody &AR,  const collider &AC,
							   Transform &BT, RigidBody & BR, const collider &BC,
							   float bounciness);