#include "Transform.h"
#include "sfwdraw.h"
vec2 Transform::getDirection()
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}

void Transform::debugDraw()
{
	sfw::drawCircle(position.x, position.y, 12);


	vec2 dirEnd = position + getDirection() * 20;
	sfw::drawLine(position.x, position.y,
		dirEnd.x, dirEnd.y, RED);
	sfw::drawLine(position.x, position.y,
		dirEnd.x - 40, dirEnd.y, RED);


	vec2 upEnd = position - perp(getDirection()) * 20;

	sfw::drawLine(position.x, position.y,
		upEnd.x, upEnd.y, GREEN);
	sfw::drawLine(position.x, position.y,
		upEnd.x, upEnd.y-40, GREEN);

	if (sfw::getKey('W'))
	{
		position += getDirection() * 3;
	}
	if (sfw::getKey('S'))
	{
		position -= getDirection() * 3;
	}

	
}
