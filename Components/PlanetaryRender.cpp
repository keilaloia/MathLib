#include "PlanetaryRender.h"
#include "sfwdraw.h"
#include "vec3.0.h"
using namespace sfw;




PlanetaryRenderer::PlanetaryRenderer(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void PlanetaryRenderer::draw(Transform & planetTrans)
{
	mat3 glob = planetTrans.getGlobalTransform();

	vec2 pos = glob[2].xy;

	float xRad = magnitude(glob * vec3{ size, 0, 0 });
	float yRad = magnitude(glob * vec3{ 0, size, 0 });

	float rad = xRad > yRad ? xRad : yRad;
	drawCircle(pos.x, pos.y, rad, 12U, color);
	

}
