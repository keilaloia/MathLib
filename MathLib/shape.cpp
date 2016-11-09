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

AABB operator*(const mat3 &T, const AABB &B)
{
	AABB boxxy;


	//float xhe = magnitude(T * vec3{ boxxy.half.x , 0, 0 });
	//float yhe = magnitude(T * vec3{ 0,boxxy.half.y,0 });

	boxxy.half = B.half;

	vec2 testMin = B.min();
	vec2 testMax = B.max();

	vec3 tp[4];
	tp[0] = T * vec3{ B.min().x, B.max().y, 1 };
	tp[1] = T * vec3{ B.max().x, B.max().y, 1 };
	tp[2] = T * vec3{ B.min().x, B.min().y, 1 };
	tp[3] = T * vec3{ B.max().x, B.min().y, 1 };

	vec2 minvec = tp[0].xy,
		maxvec = tp[0].xy;

	for (int i = 1; i < 4; ++i)
	{
		if (minvec.x > tp[i].x) // bot left
		{
			minvec.x = tp[i].x;
		}
		if (minvec.y > tp[i].y)// top left
		{
			minvec.y = tp[i].y;
		}

		if (maxvec.x < tp[i].x)// bot right
		{
			maxvec.x = tp[i].x;
		}
		if (maxvec.y < tp[i].y)//top right
		{
			maxvec.y = tp[i].y;
		}
	}

	boxxy.pos = (maxvec + minvec) / 2;
	boxxy.half = (maxvec - minvec) / 2;

	return boxxy;
}

Plane  operator*(const mat3 &T, const Plane &P)
{
	Plane retval;

	retval.pos = (T * vec3{ P.pos.x, P.pos.y, 1 }).xy;

	retval.dir = normal(T * vec3{P.dir.x, P.dir.y, 0}).xy;

	return retval;
}

bool operator==(const Plane &A, const Plane &B)
{
	return A.pos == B.pos && A.dir == B.dir;

}

Hull::Hull(const vec2 *a_vertices, unsigned a_size)
{
	size = a_size;

	for (int i = 0; i < a_size; i++)
	{
		vec2 A;
		// if it's the last vertex?
		if (i + 1 == a_size)
		{
			A = a_vertices[i] - a_vertices[0];
		}
		else
		{
			A = a_vertices[i] - a_vertices[i + 1];
		}

		vec2 absolute = normal(A);
		vec2 middle = perp(absolute);

		vertices[i] = a_vertices[i];
		normals[i] = middle;


	}
}

Hull::Hull()
{
	size = 0;
}

Hull operator*(const mat3 &T, const Hull &H)
{
	Hull retval;

	retval.size = H.size;
	for (int i = 0; i < H.size; ++i)
	{
		retval.vertices[i] = (T * vec3{ H.vertices[i].x, H.vertices[i].y, 1 }).xy;
		retval.normals[i] = (T * vec3{ H.vertices[i].x, H.vertices[i].y, 0 }).xy;
	}
	return retval;
}