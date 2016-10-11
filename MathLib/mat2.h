#pragma once
#include "vec2.0.h"

union mat2
{
	float m[4]; // single dimensional array
	float mm[2][2]; // multidimensional array
	vec2 c[2]; // column vectors

	vec2  operator[](unsigned idx) const;
	vec2 &operator[](unsigned idx);
};

bool operator ==(const mat2 & A, const mat2 & B);
bool operator != (const mat2 & A, const mat2 & B);

mat2 operator + (const mat2 & A, const mat2 & B);
mat2 operator - (const mat2 & A, const mat2 & B);
mat2 operator - (const mat2 & A);

mat2 operator * (const mat2 & A, const mat2 & B);
mat2 Transpose  (const mat2 & A);

vec2 operator * (const mat2 & A, const vec2 & B);
mat2 operator * (const mat2 & A, const float & B);
mat2 operator * (const float & A, const mat2 & B);
float determinant(const mat2 &A);
mat2 inverse(const mat2 &A);

mat2 mat2Identity();
// mat2 * mat2
// mat2 * vec2
//mat2 * float
//float * mat2

//mat2==mat2
// mat2 + mat2
//mat2 - mat2
//-mat2			unary negation