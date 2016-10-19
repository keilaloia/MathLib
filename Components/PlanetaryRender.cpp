#include "PlanetaryRender.h"
#include "sfwdraw.h"
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

	drawCircle(pos.x, pos.y, size, 12U, color);
	

}
