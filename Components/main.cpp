#include"sfwdraw.h"
#include "vec2.0.h"
#include "Transform.h"
#include <iostream>
int main()
{
	sfw::initContext();
	

	Transform trans(400, 300,KEY_LEFT_SHIFT, 'W', 'S', 'A', 'D');

	Transform tastyfreeze(600, 400, KEY_RIGHT_SHIFT, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT );
	trans.facing = 0;

	tastyfreeze.facing = 0;
	
	tastyfreeze.scale = vec2{ 80,20 };

	trans.scale = vec2{ 80,20 };

	vec2 basis = { 40, 0 };
	
	float ang_vec = 0;

	while (sfw::stepContext())
	{
		//trans.facing += sfw::getDeltaTime();
		//trans.debugDraw();
		//tastyfreeze.facing -= sfw::getDeltaTime();
		//tastyfreeze.debugDraw();
		
		ang_vec += sfw::getDeltaTime();
		vec2 incident = fromAngle(ang_vec) * 40;
		float proj = dot(basis, normal(incident));

		sfw::drawLine(400, 300, 400 + basis.x, 300 + basis.y, RED);

		sfw::drawLine(400,300, 400 + incident.x, 300 + incident.y, CYAN);
		sfw::drawLine(400, 300, 400 + proj, 300, GREEN);
	}
	sfw::termContext();

}