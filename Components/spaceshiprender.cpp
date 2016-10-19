#include "spaceshiprender.h"
#include "sfwdraw.h"

ShipRender::ShipRender()
{
}

void ShipRender::drawship(const Transform & ShipTransform, const mat3 & camera)
{
	mat3 ship = ShipTransform.getGlobalTransform();

	vec3 p1 = camera * ship * vec3{ 0, 7, 1 };
	vec3 p2 = camera * ship * vec3{ -6, 0, 1 };
	vec3 p3 = camera * ship * vec3{ 6, 0, 1 };
	vec3 p4 = camera * ship * vec3{ 0, -6, 1 };

	sfw::drawLine(p1.x, p1.y, p2.x, p2.y, CYAN);
	sfw::drawLine(p2.x, p2.y, p3.x, p3.y, CYAN);
	sfw::drawLine(p3.x, p3.y, p4.x, p4.y, CYAN);
	sfw::drawLine(p4.x, p4.y, p1.x, p1.y, CYAN);



}
