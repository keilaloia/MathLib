#include "Transform.h"
#include "sfwdraw.h"
#include "shapedraw.h"

Transform::Transform(): m_facing(0), m_position({ 0,0 }), m_scale({ 28,8 })
{


}

Transform::Transform(float x, float y)// : Transform()
{
	m_position.x = x;
	m_position.y = y;

	m_facing = 0;
	m_scale = {1,1};
	m_parent = nullptr;
}




vec2 Transform::getDirection() const
{
	return fromAngle(m_facing);
}

void Transform::setDirection(const vec2 & dir)
{
	m_facing = angle(dir);
}

mat3 Transform::getLocalTransform() const
{
	mat3 S = scale(m_scale.x, m_scale.y);
	mat3 T = translate(m_position.x, m_position.y);
	mat3 R = rotation(m_facing);
	
	return T * R * S;
}

mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
		return getLocalTransform();
	else
		return m_parent->getGlobalTransform() * getLocalTransform();
}

float Transform::getGlobalAngle() const
{
	return angle(getGlobalRight());
}

vec2 Transform::getGlobalRight() const
{
	return getGlobalTransform()[0].xy;
	
}

vec2 Transform::getGlobalUp() const
{
	return getGlobalTransform()[1].xy;

}

vec2 Transform::getGlobalPosition() const
{
	return getGlobalTransform()[2].xy;
}

void Transform::debugDraw(const mat3 &T) const
{
	mat3 L = T * getGlobalTransform();
	
	vec3 pos = L[2];
	//parent position
	vec3 p_pos = m_parent ? T *  m_parent->getGlobalTransform()[2] : pos;

	vec3 right = L * vec3{ 10,0,1 };
	vec3 up    = L * vec3{ 0,10,1 };

	//vec2 cameraPosition = vec2{ 0,0 };
	

	//mat3 view   = translate(cameraPosition.x, cameraPosition.y);
	//mat3 camera = view;
	
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);
	//sfw::drawLine(p_pos.x, p_pos.y, pos.x, pos.y, CYAN);

	drawCircle(L*Circle{ 0,0, 10 }, RED);
	//drawAABB(L * AABB{ 0, 0, 10, 10 }, CYAN);

}

