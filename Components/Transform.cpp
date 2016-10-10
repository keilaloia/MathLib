#include "Transform.h"
#include "sfwdraw.h"


Transform::Transform(): facing(0), position({ 0,0 }), scale({ 28,8 })
{


}

Transform::Transform(float x, float y)// : Transform()
{
	position.x = x;
	position.y = y;

	facing = 0;
	scale = {12,12};
}


vec2 Transform::getDirection() const
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}

void Transform::debugDraw() const
{
	

	sfw::drawCircle(position.x, position.y, 12);


	vec2 dirEnd = position + (getDirection() * scale.x);
	
	sfw::drawLine(position.x, position.y,
		dirEnd.x , dirEnd.y, RED);



	vec2 upEnd = position - perp(getDirection() * scale.y);

	sfw::drawLine(position.x, position.y,
		upEnd.x, upEnd.y, GREEN);




	
}
