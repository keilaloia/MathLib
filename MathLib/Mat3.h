#pragma once
#include "vec3.0.h"

union mat3
{
	float m[9];
	float mm[3][3];
	vec3 c[3];

	vec3 operator[](unsigned idx) const;
	vec3 &operator[](unsigned idx);

};

bool operator ==(const mat3 & A, const mat3 & B);
bool operator != (const mat3 & A, const mat3 & B);

mat3 operator + (const mat3 & A, const mat3 & B);
mat3 operator - (const mat3 & A, const mat3 & B);
mat3 operator - (const mat3 & A);

mat3 operator * (const mat3 & A, const mat3 & B);
mat3 Transpose(const mat3 & A);

vec3 operator * (const mat3 & A, const vec3 & B);
mat3 operator * (const mat3 & A, const float & B);
mat3 operator * (const float & A, const mat3 & B);
float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);
mat3 mat3Identity();

mat3 scale(float w, float h);
mat3 translate(float X, float Y);
mat3 rotation(float a);