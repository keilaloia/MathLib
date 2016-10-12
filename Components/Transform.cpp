#include "Transform.h"
#include "sfwdraw.h"


Transform::Transform(): m_facing(0), m_position({ 0,0 }), m_scale({ 28,8 })
{


}

Transform::Transform(float x, float y)// : Transform()
{
	m_position.x = x;
	m_position.y = y;

	m_facing = 0;
	m_scale = {12,12};
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
	
	return T * S * R;
}

void Transform::debugDraw(const mat3 &T) const
{
	


	mat3 L = T * getLocalTransform();
	
	vec3 pos = L[2];

	vec3 right = pos+L*vec3{ 7,0,0 };
	vec3 up    = pos+L*vec3{ 0,1,0 };
	
	//vec2 dirEnd = m_position + (getDirection() * m_scale.x);
	
	sfw::drawLine(pos.x, pos.y,
		right.x , right.y, RED);



	//vec2 upEnd = m_position - perp(getDirection() * m_scale.y);

	sfw::drawLine(pos.x, pos.y,
		up.x, up.y, GREEN);

	sfw::drawCircle(pos.x, pos.y,12, 12, RED);



	
}
