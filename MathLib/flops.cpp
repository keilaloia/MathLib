#include "flops.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cfloat>
bool fequal(float lhs, float rhs)
{
	if (fabs(lhs - rhs) < 0.00001)
		return true;
	else
		return false;
}

float deg2rad(float deg)
{
	return deg * M_PI / 180.f;
}

float rad2deg(float rad)
{
	return (rad*180.f) / M_PI;
}

float linearHalf(float x)
{
	return 0.5f*x;
}

float slowStart(float x)
{
	return x*x;
}

float fastStart(float x)
{
	return 1 - (1 - x)*(1 - x);
}

float invert(float x)
{
	return -abs(2*(x) -1) +1;
}

float Bounce(float x)
{
	return abs(cos(x * 10)*(1 - x));
}

float flipBounce(float x)
{
	return 1 - Bounce(x);
}

float parabFlip(float x)
{
	return  -(4 * (x*x)) + (4 * x) + 0;

}

float lerp(float start, float end, float alpha)
{
	// avoids some issues with floating point numbers
	return (1 - alpha)*start + (alpha)*end;

	//slope intercept form, where alpha is x
	//y = m*x +b
	//return alpha*(end - start) + start;
}

float quadBezier(float start, float mid, float end, float alpha)
{
	return
		lerp(

			lerp(start, mid, alpha),
			lerp(mid, end, alpha),

		alpha);

}

float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha)
{
	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	float point = (h00 * start) + (h10 * s_tan) + (h01 * end) + (h11 * e_tan);

	return point;
}

float cardinalSpline(float start, float mid, float end, float tightness, float alpha)
{
	float buttercup = (mid - start) * tightness;
	float snowball = (end - mid) * tightness;

	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;
	
	float point = (h00 * start) + (h10 * buttercup) + (h01 * end) + (h11 * snowball);

	return point;
}

float catRomSpline(float start, float mid, float end, float alpha)
{
	return cardinalSpline(start, mid, end, .5, alpha);
}
