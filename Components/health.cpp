#include "health.h"

Health::Health()
{
	visualWidth = 15;
}

void Health::debugDraw(const mat3 & T, const Transform & trans)
{
	vec2 p = (T * trans.getGlobalTransform())[2].xy;
	//vec2 v = p + camera;
	//vec2 a;


	//sfw::drawLine(p.x + 20 , p.y, p.x - 20 , p.y, RED);

	sfw::drawLine(p.x + visualWidth, p.y, p.x - visualWidth, p.y, RED);


	sfw::drawLine(p.x + visualWidth *(health/maxHealth), p.y, p.x - visualWidth * (health / maxHealth), p.y, GREEN);
}