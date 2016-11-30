#include "collider.h"
#include "shapedraw.h"
#include<cmath>

collider::collider()
{

}

collider::collider(const vec2 * verts, int size): hull(verts, size)
{

	float minx = INFINITY;
	float miny = INFINITY;
	float maxX = -INFINITY;
	float maxY = -INFINITY;

	for (int i = 0; i < size; ++i)
	{
		if (minx > verts[i].x)
		{
			minx = verts[i].x;
		}
		if (miny > verts[i].y)
		{
			miny = verts[i].y;
		}
		if (maxX < verts[i].x)
		{
			maxX = verts[i].x;
		}
		if (maxY < verts[i].y)
		{
			maxY = verts[i].y;
		}
	}
	vec2 max  = { maxX, maxY };
	vec2 min  = { minx, miny };
	box.half = (max - min) / 2;
	box.pos =  (max + min) / 2;

	
}

void collider::DebugDraw(const mat3 & T, const Transform & trans)
{
	drawAABB((T * trans.getGlobalTransform()) * box,  0x888888ff);
	drawHull(T * trans.getGlobalTransform() * hull, 0x888888ff);
}

CollisionData ColliderCollision(const Transform & AT, const Transform & BT, const collider & AC, const collider & BC, bool boxOnly)
{
	CollisionData retval;
	retval = boxCollision(AT.getGlobalTransform() * AC.box,
						  BT.getGlobalTransform() * BC.box);



	if (retval.penetrationDepth >= 0 && !boxOnly)
		retval = HullCollision (AT.getGlobalTransform() * AC.hull,
								BT.getGlobalTransform() * BC.hull);

	return retval;
}




CollisionData StaticCollisionBox(Transform & AT, RigidBody & AR, const collider & AC, const Transform & BT, const collider & BC, float bounciness)
{

	CollisionData results = ColliderCollision(AT, BT, AC, BC, true);
	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= MTV;

		AR.velocity = reflect(AR.velocity, results.collisionNormal) ;
	
	}
	return results;
}

CollisionData StaticCollision(Transform & AT, RigidBody & AR, const collider & AC, const Transform & BT, const collider & BC, float bounciness)
{

	CollisionData results = ColliderCollision(AT, BT, AC, BC);
	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= MTV;

		AR.velocity = reflect(AR.velocity, results.collisionNormal);
	}
	return results;
}

CollisionData DynamicCollision(Transform & AT, RigidBody & AR, const collider & AC, Transform & BT,
	RigidBody & BR, const collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, BT, AC, BC);

	if (results.penetrationDepth >= 0)
	{	
		vec2 MTV = results.penetrationDepth * results.collisionNormal;

		float am = magnitude(AR.mass * AR.velocity);
		float bm = magnitude(BR.mass * BR.velocity);
		float cm = am + bm;
		AT.m_position -= MTV * (bm / cm);
		BT.m_position += MTV * (am / cm);


		vec2 X = (((AR.velocity * AR.mass) + (BR.velocity * BR.mass)) +
				   (-bounciness * (AR.velocity - BR.velocity)) * BR.mass) / (BR.mass + AR.mass);

		vec2 Y = bounciness *(AR.velocity - BR.velocity) - ((AR.velocity * AR.mass) + (BR.velocity * BR.mass) +
			   (-bounciness *(AR.velocity - BR.velocity)) * BR.mass) / (BR.mass + AR.mass);

		AR.velocity = X;
		BR.velocity = Y;

	}
		return results;
}
