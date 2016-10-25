#include "shape.h"
#include "flops.h"

Circle operator*(const mat3 &T, const Circle &C)
{
	Circle retval;
	retval.pos = (T*vec3{ C.pos.x, C.pos.y, 1 }).xy;
	retval.radius = C.radius;

	float xRad = magnitude(T * vec3{ C.radius, 0, 0 });
	float yRad = magnitude(T * vec3{ 0, C.radius, 0 });
	retval.radius = xRad > yRad ? xRad : yRad;
	
	/*vec2 position = T.pos;*/
	return retval;
}

bool operator==(const Circle &A, const Circle &B)
{
	return (A.pos == B.pos) && fequal(A.radius, B.radius);

}

vec2 AABB::min() const
{
	
	return pos - half;
}

vec2 AABB::max() const
{
	return pos + half;
}

