#include "Mat3.h"
#include "flops.h"
#include "cmath"

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

mat3 operator * (const float & A, const mat3 & B)
{
	return B*A;
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
	// A = rows B columns


	return{
		(A.m[0] * B.m[0]) + (A.m[3] * B.m[1]) + (A.m[6] * B.m[2]), // col 1, row 1
		(A.m[1] * B.m[0]) + (A.m[4] * B.m[1]) + (A.m[7] * B.m[2]),		  // row 2
		(A.m[2] * B.m[0]) + (A.m[5] * B.m[1]) + (A.m[8] * B.m[2]),		  // row 3
		(A.m[0] * B.m[3]) + (A.m[3] * B.m[4]) + (A.m[6] * B.m[5]), // col 2, row 1
		(A.m[1] * B.m[3]) + (A.m[4] * B.m[4]) + (A.m[7] * B.m[5]),		  // row 2
		(A.m[2] * B.m[3]) + (A.m[5] * B.m[4]) + (A.m[8] * B.m[5]),
		(A.m[0] * B.m[6]) + (A.m[3] * B.m[7]) + (A.m[6] * B.m[8]), // col 3
		(A.m[1] * B.m[6]) + (A.m[4] * B.m[7]) + (A.m[7] * B.m[8]),
		(A.m[2] * B.m[6]) + (A.m[5] * B.m[7]) + (A.m[8] * B.m[8])
		  };
}

vec3 operator * (const mat3 & A, const vec3 & B)
{
	return vec3{ (A.m[0] * B.x) + (A.m[1] * B.y) + (A.m[2] * B.z),
				 (A.m[3] * B.x) + (A.m[4] * B.y) + (A.m[5] * B.z),
				 (A.m[6] * B.x) + (A.m[7] * B.y) + (A.m[8] * B.z)
			   };

}

float determinant(const mat3 &A)
{
	float B = { (A.m[0] * A.m[4] * A.m[8]) + 
				(A.m[3] * A.m[7] * A.m[2]) + 
				(A.m[6] * A.m[1] * A.m[5]) -
			    (A.m[6] * A.m[4] * A.m[2]) - 
				(A.m[3] * A.m[1] * A.m[8]) - 
				(A.m[0] * A.m[7] * A.m[5]) };

	return B;
}

mat3 inverse(const mat3 &A)
{
	
	float a = A.m[0]; 
	float b = A.m[1]; 
	float c = A.m[2];
	float d = A.m[3];
	float e = A.m[4];
	float f = A.m[5];
	float g = A.m[6];
	float h = A.m[7];
	float i = A.m[8];

	float Aa = determinant({ e,i,f,h });
	float B = -determinant({ d,i,f,g });
	float C =  determinant({ d,h,e,g });
	float D = -determinant({ b,i,c,h });
	float E =  determinant({ a,i,c,g });
	float F = -determinant({ a,h,b,g });
	float G =  determinant({ b,f,c,e });
	float H = -determinant({ a,f,c,d });
	float I =  determinant({ a,e,b,d });

	return (1 / determinant(A)) * mat3 { Aa, B, C, D, E, F, G, H, I };

}

mat3 mat3Identity()
{
	return mat3{ 1,0,0,0,1,0,0,0,1 };
}

mat3 scale(float W, float H)
{
	return mat3{ { W,0,0,0,H,0,0,0,1 } };
}
mat3 rotation(float a)
{
	return mat3{ {cos(a), -sin(a), 0, sin(a), cos(a), 0, 0,0,1} };
}
mat3 translate(float X, float Y)
{
	return mat3{ {1,0,X, 0,1,Y,0,0,1 } };
};
	

