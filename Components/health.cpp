#include "health.h"

void Health::debugDraw(const mat3 & T, const Transform & trans)
{
	vec2 p = (T * trans.getGlobalTransform())[2].xy;
	//vec2 v = p + camera;
	//vec2 a;


	sfw::drawLine(p.x + 15, p.y, p.x - 15, p.y, RED);


	sfw::drawLine(p.x + 15 *(health/100.f), p.y, p.x - 15 * (health / 100.f), p.y, GREEN);
}