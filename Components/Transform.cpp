#include "Transform.h"
#include "sfwdraw.h"


Transform::Transform(): facing(0), position({ 0,0 }), scale({ 28,8 })
{


}

Transform::Transform(float x, float y,int sprint, int up, int down, int left, int right)// : Transform()
{
	position.x = x;
	position.y = y;

	Upkey = up;
	Downkey = down;
	rLeft = left;
	rRight = right;

	Sprint = sprint;

}


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


	vec2 dirEnd = position + getDirection() * scale.x;
	sfw::drawLine(position.x, position.y,
		dirEnd.x, dirEnd.y, RED);
	sfw::drawLine(position.x, position.y,
		dirEnd.x - 40, dirEnd.y, RED);


	vec2 upEnd = position - perp(getDirection() * scale.y);

	sfw::drawLine(position.x, position.y,
		upEnd.x, upEnd.y, GREEN);
	sfw::drawLine(position.x, position.y,
		upEnd.x, upEnd.y-40, GREEN);

	if (sfw::getKey(Upkey))
	{
		position += getDirection() * 3;
	}
	if (sfw::getKey(Downkey))
	{
		position -= getDirection() * 3;
	}
	if (sfw::getKey(rLeft))
	{
		facing -= sfw::getDeltaTime() * 2;
	}
	if (sfw::getKey(rRight))
	{
		facing += .1;
	}
	if (sfw::getKey(Upkey) && sfw::getKey(Sprint))
	{
		position += getDirection() * 20;
	}
	if (sfw::getKey(Downkey) && sfw::getKey(Sprint))
	{
		position -= getDirection() * 20;
	}
	
}
