#pragma once
#include <cstdio>

struct vec2
{
	float x, y, z;

};

//component subtraction
vec2 operator -(const vec2 &lhs, const vec2 &rhs);
//component addition
vec2 operator +(const vec2 &lhs, const vec2 &rhs);
//scalar multiplication
vec2 operator *(const vec2 &lhs, float rhs);
vec2 operator *(float rhs, const vec2 &lhs);		// TODOOO FLIP ME
//scalar division
vec2 operator/(const vec2 &lhs, float rhs);

//unary Negation
vec2 operator-(const vec2 &v);

//Relational Operators
//component equivalence
bool operator==(const vec2 &lhs, const vec2 &rhs);
//component Non-equivalence
bool operator!=(const vec2 &lhs, const vec2 &rhs);

//assignment Component Addition
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
//Assignment Component Subtraction
vec2 &operator-=( vec2 &lhs, const vec2 &rhs);
//Assignemtn Scalar Multiplication
vec2 &operator*=( vec2 &lhs, float rhs);
//Assignment Scalar Division
vec2 &operator/=(vec2 &lhs, float rhs);

//how long a vector is

float magnitude(const vec2 &v);

//normalizing reduces its length to one
vec2 normal(const vec2 &v);

//Ax*Bx+Ay*By
float dot(const vec2 &rhs, const vec2 &lhs);

//(a2b3- a3b2,a3b1 -a1b3,a1b2-a2b1
float angleBetween(const vec2 &rhs, const vec2 &lhs);

//find a right angle perpendicular vector (2D only!)
//(y, -x)
vec2 perp(const vec2 &v);
//find the angle of the vector(2d only!)
float angle(const vec2 &v);
//find angle between two vectors
vec2 fromAngle(float a);

vec2 lerp(const vec2 start, const  vec2 end, float alpha);

vec2 quadBezier(const vec2 start, const  vec2 mid, const  vec2 end, float alpha);

vec2 hermiteSpline(const vec2 start, const  vec2 s_tan, const  vec2 end, const  vec2 e_tan, float alpha);

vec2 cardinalSpline(const vec2 start, const  vec2 mid, const vec2 end, float tightness, float alpha);

vec2 catRomSpline(const vec2 start, const  vec2 mid, const  vec2 end, float alpha);