#pragma once
#include "mat3.h"

struct Circle 
{
	vec2 pos;// offest usually not on screen space
	float radius; 
};


Circle operator*(const mat3 &T, const Circle &C);
bool   operator==(const Circle &A, const Circle &B);

struct AABB
{
	vec2 pos, half;// half is half extents

	vec2 min() const;
	vec2 max() const;
};
struct Plane
{
	vec2 pos, dir;
};
Plane  operator*(const mat3 &T, const Plane &P);
bool   operator*(const Plane&A, const Plane &B);
void drawPlane(const Plane & p, unsigned color);

struct Ray{};

struct Hull
{
	vec2 position;

	vec2 vertices[16];
	vec2 normals[16];
	unsigned int size;

	Hull(const vec2 *a_vertices, unsigned a_size);
	Hull();
};
bool   operator==(const Hull &A, const Hull &B);
Hull   operator*(const mat3 &T, const Hull &H);


AABB   operator*(const mat3 &T, const AABB &B);
Ray    operator*(const mat3 &T, const Ray &R);
