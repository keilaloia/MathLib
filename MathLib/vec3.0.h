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
// TODO: *= float vec3
//Assignment Scalar Division
vec3 &operator/=(vec3 &lhs, float rhs);

//how long a vector is
float magnitude(const vec3 &v);


float angleBetween(const vec3 & lhs, const vec3 & rhs);

//Ax*Bx+Ay*By+Az*Bz
float dot(const vec3 &lhs, const vec3 &rhs);

//find a vector perpendicular to the plane created by two vectors
//(a2b3- a3b2,a3b1 -a1b3,a1b2-a2b1

vec3 cross(const vec3 &lhs, const vec3 & rhs);

