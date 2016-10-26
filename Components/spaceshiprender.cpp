#include "spaceshiprender.h"
#include "sfwdraw.h"
#include "shapedraw.h"

ShipRender::ShipRender()
{
	
}

void ShipRender::drawship(const Transform & ShipTransform, const mat3 & camera)
{
	mat3 ship = ShipTransform.getGlobalTransform();

	vec3 p1 = camera * ship * vec3{ 0, 7, 1 };		// top
	vec3 p2 = camera * ship * vec3{ -6, 0, 1 };		// left
	vec3 p3 = camera * ship * vec3{ 6, 0, 1 };		// right
	vec3 p4 = camera * ship * vec3{ 0, -6, 1 };		// bottom

	sfw::drawLine(p1.x, p1.y, p3.x, p3.y, CYAN);
	sfw::drawLine(p3.x, p3.y, p4.x, p4.y, CYAN);
	sfw::drawLine(p4.x, p4.y, p2.x, p2.y, CYAN);
	sfw::drawLine(p2.x, p2.y, p1.x, p1.y, CYAN);
	sfw::drawLine(p1.x, p1.y, p4.x, p4.y, CYAN);
	sfw::drawLine(p2.x, p2.y, p3.x, p3.y, CYAN);

	AABB shipAABB = { 0, 0, 6, 6.5 };

	drawAABB( camera * ship * shipAABB, CYAN);



}
