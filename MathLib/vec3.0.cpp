#include "vec3.0.h"
#include <cmath>

vec3 operator+(const vec3 &lhs, const vec3 &rhs)
{
	return vec3{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

vec3 operator*(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator*(float rhs, const vec3 & lhs)
{
	return vec3{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator-(const vec3 & v)
{
	return vec3{ -v.x, -v.y , -v.z};
}

vec3 & operator+=(vec3 & lhs, const vec3 & rhs)
{

	return lhs = lhs + rhs;
	// TODO: insert return statement here
}

vec3 & operator-=(vec3 & lhs, vec3 & rhs)
{
	return lhs = lhs - rhs;
	// TODO: insert return statement here
}

vec3 & operator*=(vec3 & lhs, float rhs)
{
	return lhs = lhs* rhs;
	// TODO: insert return statement here
}


vec3 & operator/=(vec3 & lhs, float rhs)
{
	return lhs = lhs / rhs;
	// TODO: insert return statement here
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	return (lhs.x == rhs.x) && (lhs.y == rhs.y)&&(lhs.z == rhs.z);

}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{

	return (lhs.x != rhs.x) && (lhs.y != rhs.y)&&(lhs.z != rhs.z);
}

vec3 operator/(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x / rhs, lhs.y / rhs, lhs.z/rhs };
}

float magnitude(const vec3 & v)
{
	return sqrt((v.x*v.x) + (v.y *v.y) + (v.z *v.z));
}


