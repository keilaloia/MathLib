#include "Mat3.h"
#include "flops.h"

vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}

bool operator == (const mat3 & A, const mat3 & B)
{
	return  fequal(A.m[0], B.m[0]) &&
			fequal(A.m[1], B.m[1]) &&
			fequal(A.m[2], B.m[2]) &&
			fequal(A.m[3], B.m[3]) &&
			fequal(A.m[4], B.m[4]) &&
			fequal(A.m[5], B.m[5]) &&
			fequal(A.m[6], B.m[6]) &&
			fequal(A.m[7], B.m[7]) &&
			fequal(A.m[8], B.m[8]);
}
bool operator != (const mat3 & A, const mat3 & B)
{
	return  !fequal(A.m[0], B.m[0]) ||
			!fequal(A.m[1], B.m[1]) ||
			!fequal(A.m[2], B.m[2]) ||
			!fequal(A.m[3], B.m[3]) ||
			!fequal(A.m[4], B.m[4]) ||
			!fequal(A.m[5], B.m[5]) ||
			!fequal(A.m[6], B.m[6]) ||
			!fequal(A.m[7], B.m[7]) ||
			!fequal(A.m[8], B.m[8]);

}

mat3 operator + (const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] + B.m[0],
				 A.m[1] + B.m[1],
				 A.m[2] + B.m[2],
				 A.m[3] + B.m[3],
				 A.m[4] + B.m[4],
				 A.m[5] + B.m[5],
				 A.m[6] + B.m[6],
				 A.m[7] + B.m[7],
				 A.m[8] + B.m[8] };
}		

mat3 operator - (const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] - B.m[0],
				 A.m[1] - B.m[1],
				 A.m[2] - B.m[2],
				 A.m[3] - B.m[3],
				 A.m[4] - B.m[4],
				 A.m[5] - B.m[5],
				 A.m[6] - B.m[6],
				 A.m[7] - B.m[7],
				 A.m[8] - B.m[8] };
}

mat3 operator -(const mat3 & A)
{

	return{ -A.m[0],
			-A.m[1],
			-A.m[2],
			-A.m[3],
			-A.m[4],
			-A.m[5],
			-A.m[6],
			-A.m[7],
			-A.m[8] };
}

mat3 operator * (const mat3 & A, const float & B)
{
	return mat3{ (A.m[0] * B),
				 (A.m[1] * B),
				 (A.m[2] * B),
				 (A.m[3] * B),
				 (A.m[4] * B),
				 (A.m[5] * B),
				 (A.m[6] * B),
				 (A.m[7] * B),
				 (A.m[8] * B) };
}

mat3 Transpose(const mat3 & A)
{
	mat3 retval = A;

	retval.m[0] = A.m[0];
	retval.m[3] = A.m[1];
	retval.m[6] = A.m[2];
	retval.m[1] = A.m[3];
	retval.m[4] = A.m[4];
	retval.m[7] = A.m[5];
	retval.m[2] = A.m[6];
	retval.m[5] = A.m[7];
	retval.m[8] = A.m[8];

	return A;
}

mat3 operator * (const mat3 & A, const mat3 & B)
{
	//1,1
	//2,1
	//3,1
	//1,2
	//2,2
	//3,2
	//1,3
	//2,3
	//3,3

	return{ (A.m[0] * B.m[0]) + (A.m[2] * B.m[1]),
		(A.m[1] * B.m[0]) + (A.m[3] * B.m[1]),
		(A.m[0] * B.m[2]) + (A.m[2] * B.m[3]),
		(A.m[1] * B.m[2]) + (A.m[3] * B.m[3]) };
}