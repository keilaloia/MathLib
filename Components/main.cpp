#include"sfwdraw.h"
#include "vec2.0.h"
#include "Transform.h"
#include <iostream>
int main()
{
	sfw::initContext();
	Transform trans;

	trans.facing = 0;
	trans.position = vec2{ 400, 300 };
	trans.scale = vec2{ 12, 8 };
	while (sfw::stepContext())
	{
		trans.facing += sfw::getDeltaTime();
		trans.debugDraw();

		
	}
	sfw::termContext();

}