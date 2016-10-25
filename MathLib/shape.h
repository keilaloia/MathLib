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
struct Plane{};
struct Ray{};
struct Hull{};

AABB   operator*(const mat3 &T, const AABB &B);

Plane  operator*(const mat3 &T, const Plane &P);
Ray    operator*(const mat3 &T, const Ray &R);
Hull   operator*(const mat3 &T, const Hull &H);