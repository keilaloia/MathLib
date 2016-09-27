#pragma once
struct vec2
{
	float x, y;

};

//component subtraction
vec2 operator -(const vec2 &lhs, const vec2 &rhs);
//component addition
vec2 operator +(const vec2 &lhs, const vec2 &rhs);
//scalar multiplication
vec2 operator *(const vec2 &lhs, float rhs);
vec2 operator *(float rhs, const vec2 &lhs);
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


float magnitude(const vec2 &v);