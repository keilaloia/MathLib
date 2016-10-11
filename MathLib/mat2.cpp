#include "mat2.h"
#include "flops.h"

vec2 mat2::operator[](unsigned idx) const
{
	return c[idx];
}

vec2 & mat2::operator[](unsigned idx)
{
	return c[idx];
}

bool operator ==(const mat2 & A, const mat2 & B)
{

	return fequal(A.m[0], B.m[0]) &&
		   fequal(A.m[1], B.m[1]) &&
		   fequal(A.m[2], B.m[2]) &&
		   fequal(A.m[3], B.m[3]);
}

mat2 operator + (const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] + B.m[0],
				 A.m[1] + B.m[1],
				 A.m[2] + B.m[2],
				 A.m[3] + B.m[3] };
}

mat2 operator - (const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] - B.m[0],
			     A.m[1] - B.m[1],
				 A.m[2] - B.m[2],
				 A.m[3] - B.m[3] };
}

mat2 operator -(const mat2 & A)
{

	return{ -A.m[0], 
			-A.m[1],
			-A.m[2],
			-A.m[3]};
}


mat2 Transpose(const mat2 & A)
{
	mat2 retval = A;

	retval.m[1] = A.m[2];
	retval.m[2] = A.m[1];

	return A;
}

mat2 operator * (const mat2 & A, const mat2 & B)
{
	//1,1
	//2,1
	//1,2
	//2,2
	
	return{  (A.m[0] * B.m[0]) + (A.m[2] * B.m[1]),
			 (A.m[1] * B.m[0]) + (A.m[3] * B.m[1]),
			 (A.m[0] * B.m[2]) + (A.m[2] * B.m[3]),
			 (A.m[1] * B.m[2]) + (A.m[3] * B.m[3]) };
} 

vec2 operator * (const mat2 & A, const vec2 & B)
{
	return vec2{ (A.m[0] * B.x) + (A.m[1] * B.y),
				 (A.m[2] * B.x) + (A.m[3] * B.y) };
}

mat2 operator * (const mat2 & A, const float & B)
{
	return mat2{ (A.m[0] * B),
				 (A.m[1] * B),
				 (A.m[2] * B),
				 (A.m[3] * B) };
}

mat2 operator * (const float & A, const mat2 & B)
{
	return B*A;

}

float determinant (const mat2 & A)
{
	float B = { (A.m[0] * A.m[3]) - (A.m[2] * A.m[1]) };

	return B;
}

bool operator != (const mat2 & A, const mat2 & B)
{
	return  !fequal(A.m[0], B.m[0]) ||
			!fequal(A.m[1], B.m[1]) ||
			!fequal(A.m[2], B.m[2]) ||
			!fequal(A.m[3], B.m[3]);

}

mat2 inverse(const mat2 &A)
{
	mat2 G = { A.m[3], -A.m[1], -A.m[2], A.m[0] };
	return (1 / determinant(A)) * G;
}

mat2 mat2Identity()
{
	return mat2{ 1,0,0,1 };
}
