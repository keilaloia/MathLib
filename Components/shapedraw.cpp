#include "shapedraw.h"
#include "sfwdraw.h"


void drawCircle(const Circle & C,unsigned color)
{
	
	sfw::drawCircle(C.pos.x, C.pos.y, C.radius, 12U, color);

}

void drawAABB(const AABB &E, unsigned color)
{
	/*mat3 box = boxTransform.getGlobalTransform();
	vec3 A = box * vec3{ E.min().x, E.max().y, 1 };
	vec3 B = box * vec3{ E.max().x, E.min().y, 1 };
	vec3 C = box * vec3{ E.min().x, E.min().y, 1 };
	vec3 D = box * vec3{ E.max().x, E.max().y, 1 };*/

	sfw::drawLine(E.min().x, E.min().y, E.max().x, E.min().y, color);
	sfw::drawLine(E.min().x, E.min().y, E.min().x, E.max().y, color);
	sfw::drawLine(E.min().x, E.max().y, E.max().x, E.max().y, color);
	sfw::drawLine(E.max().x, E.min().y, E.max().x, E.max().y, color);

	//sfw::drawLine(A.x * )
}
