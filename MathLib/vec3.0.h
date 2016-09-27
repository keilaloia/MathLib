#pragma once
struct vec3
{
	float x, y,z;

};

//component subtraction
vec3 operator -(const vec3 &lhs, const vec3 &rhs);
//component addition
vec3 operator +(const vec3 &lhs, const vec3 &rhs);
//scalar multiplication
vec3 operator *(const vec3 &lhs, float rhs);
vec3 operator *(float rhs, const vec3 &lhs);
//scalar division
vec3 operator/(const vec3 &lhs, float rhs);

//unary Negation
vec3 operator-(const vec3 &v);

//Relational Operators
//component equivalence
bool operator==(const vec3 &lhs, const vec3 &rhs);
//component Non-equivalence
bool operator!=(const vec3 &lhs, const vec3 &rhs);

//assignment Component Addition
vec3 &operator+=(vec3 &lhs, const vec3 &rhs);
//Assignment Component Subtraction
vec3 &operator-=(vec3 &lhs, const vec3 &rhs);
//Assignemtn Scalar Multiplication
vec3 &operator*=(vec3 &lhs, float rhs);
//Assignment Scalar Division
vec3 &operator/=(vec3 &lhs, float rhs);


float magnitude(const vec3 &v);