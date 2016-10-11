#include "vec2.0.h"
#include "flops.h"
#include <cmath>

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator+(const vec2 &lhs, const vec2 &rhs)
{
	return vec2{ lhs.x + rhs.x, lhs.y + rhs.y };
}

vec2 operator*(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x * rhs, lhs.y * rhs };
}

vec2 operator*(float rhs, const vec2 & lhs)
{
	return vec2{ lhs.x * rhs, lhs.y * rhs };
}

vec2 operator-(const vec2 & v)
{
	return vec2{ -v.x, -v.y };
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{

	return lhs = lhs + rhs;
	
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
	
}

vec2 & operator*=(vec2 & lhs, float rhs)
{
	return lhs = lhs* rhs;
	
}


vec2 & operator/=(vec2 & lhs, float rhs)
{
	return lhs = lhs / rhs;
	
}



bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return fequal(lhs.x, rhs.x) && fequal(lhs.y,rhs.y);

}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return !(lhs == rhs);
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x / rhs, lhs.y / rhs };
}

float magnitude(const vec2 & v)
{
	return sqrt((v.x*v.x) + (v.y *v.y));
}

vec2 normal(const vec2 & v)
{
	return v / magnitude(v);
}

float dot(const vec2 & lhs, const vec2 & rhs)
{
	return (lhs.x*rhs.x) + (lhs.y*rhs.y);
}

float angleBetween(const vec2 & lhs, const vec2 & rhs)
{
	return acos(dot(normal(lhs), normal(rhs)));
}

vec2 perp(const vec2 & v)
{
	return vec2{ v.y, -v.x };
}

float angle(const vec2 & v)
{
	return atan2f(v.x, v.y);
}

vec2 fromAngle(float a)
{
	return vec2{ cos(a), sin(a) };
}

vec2 lerp(const vec2 start, const vec2 end, float alpha)
{
	return (1 - alpha)*start + (alpha)*end;

	
}

vec2 quadBezier(const vec2 start, const vec2 mid, const vec2 end, float alpha)
{
	vec2 retval;

		retval.x = (start.x, end.x, alpha);
		retval.y = (start.y, end.y, alpha);
			
	return retval;
}

vec2 hermiteSpline(const vec2 start, const vec2 s_tan, const vec2 end, const vec2 e_tan, float alpha)
{
	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	vec2 point = (h00 * start) + (h10 * s_tan) + (h01 * end) + (h11 * e_tan);

	return point;
}

vec2 cardinalSpline(const vec2 start, const vec2 mid, const vec2 end, float tightness, float alpha)
{
	vec2 buttercup = (mid - start) * tightness;
	vec2 snowball = (end - mid) * tightness;
	
	
	vec2 point = hermiteSpline(start, buttercup, end, snowball, alpha);
	return point;
}

vec2 catRomSpline(const vec2 start, const vec2 mid, const vec2 end, float alpha)
{
	return cardinalSpline(start, mid, end, .5, alpha);
}

vec2 Velocity(vec2 position, float time)
{
	vec2 v = position / time;
		
	return v;
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec2::operator[](unsigned idx)
{
	return v[idx];
}
