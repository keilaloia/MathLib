#include "collision.h"
#include <cmath>
CollisionData1D collisionDetection1D(float A_min, float A_max, float B_min, float B_max)
{
	CollisionData1D retval;
	//retval.penetrationDepth
	float P = (B_max - A_min);
	float T = (A_max - B_min);
	float value;
	//retval.collisionNormal  = (A_max - B_min, B_max - A_min);
	//retval.penetrationDepth = (A_max - B_min) - (B_max - A_min);

	if (P > T)
	{
		value = T;
		retval.collisionNormal = 1;
	}
	else
	{
		value = P;
		 retval.collisionNormal = -1;

	}

	retval.penetrationDepth = value;
	retval.result = retval.penetrationDepth >= 0;
	retval.MTV = retval.penetrationDepth * retval.collisionNormal;
	return retval;
}

SweptCollisionData1D sweptDetection1D(float A_min, float A_max, float A_velocity, float B_min, float B_max, float B_velocity)
{
	SweptCollisionData1D retval;
	

	float tL = (A_min - B_max) / (B_velocity - A_velocity);
	float tR = (B_min - A_max) / (A_velocity - B_velocity);
	retval.collisionNormal = copysignf(1, tL - tR);

	
	if (tL > tR)
	{
		retval.exitTime = tL;
		retval.entryTime = tR;
	}
	else 
	{
		retval.exitTime = tR;
		retval.entryTime = tL;
	}

	return retval;
}

bool SweptCollisionData1D::result() const
{
	return entryTime >= 0 && exitTime <= 1;
}

CollisionData boxCollision(const AABB & A, const AABB & B)
{
	CollisionData1D X = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);
	CollisionData1D Y = collisionDetection1D(A.min().y, A.max().y, B.min().y, B.max().y);

	CollisionData retval;
	if (X.penetrationDepth > Y.penetrationDepth)
	{
		retval.penetrationDepth = Y.penetrationDepth;
		retval.collisionNormal = vec2{ 0 , Y.collisionNormal };
	}
	else
	{
		retval.penetrationDepth = X.penetrationDepth;
		retval.collisionNormal = vec2{ X.collisionNormal , 0 };

	}

	return retval;
}

CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB)
{
	SweptCollisionData1D X = sweptDetection1D(A.min().x, A.max().x, dA.x, B.min().x, B.max().x, dA.x);
	SweptCollisionData1D Y = sweptDetection1D(A.min().y, A.max().y, dA.y, B.min().y, B.max().y, dA.y);

	CollisionDataSwept retval;
	vec2 a;
	float h;

	if (X.entryTime > Y.entryTime && !isinf(X.entryTime))
	{
		a = { 1, 0 };
		h = X.collisionNormal;
		retval.entryTime = X.entryTime;
	}
	else
	{
		a = { 0, 1 };
		h = Y.collisionNormal;
		retval.entryTime = Y.entryTime;
	}

	retval.collisionNormal = h * a;

	if (Y.exitTime < X.exitTime || !isinf(X.exitTime))
	{
		retval.exitTime = Y.exitTime;
	}
	else
	{
		retval.exitTime = X.exitTime;
	}
	return retval;

}

CollisionData planeBoxCollision(const Plane & p, const AABB & b)
{
	CollisionData retval;

	vec2 BL{ b.min().x, b.min().y },
		BR{ b.max().x, b.min().y },
		TL{ b.min().x, b.max().y },
		TR{ b.max().x, b.max().y };

	float Pmax = dot(p.pos, p.dir);


	float FBL = dot(p.dir, BL),
		FBR = dot(p.dir, BR),
		FTL = dot(p.dir, TL),
		FTR = dot(p.dir, TR);

	float Amin = fminf(fminf(FBL, FBR), fminf(FTL, FTR));
	float Amax = fmaxf(fmaxf(FBL, FBR), fmaxf(FTL, FTR));
	
	retval.penetrationDepth = Pmax - Amin;
	retval.collisionNormal = p.dir;
	return retval;
}

CollisionDataSwept planeBoxCollisionSwept(const Plane & p, const AABB & b, const vec2 & bvel)
{
	CollisionDataSwept retval;

	vec2 BL{ b.min().x, b.min().y },
		 BR{ b.max().x, b.min().y },
	     TL{ b.min().x, b.max().y },
		 TR{ b.max().x, b.max().y };

	float Pmax = dot(p.pos, p.dir);
	float Bvel = dot(p.dir, bvel);

	float FBL = dot(p.dir, BL),
		FBR = dot(p.dir, BR),
		FTL = dot(p.dir, TL),
		FTR = dot(p.dir, TR);

	float Amin = fminf(fminf(FBL, FBR), fminf(FTL, FTR));
	float Amax = fmaxf(fmaxf(FBL, FBR), fmaxf(FTL, FTR));

	retval.entryTime = (Amin - Pmax) / (0 - Bvel);
	retval.exitTime = (Amax - Pmax) / (0 - Bvel);

	return retval;
}

CollisionData HullCollision(const Hull & A, const Hull & B)
{
	int size = 0;
	vec2 axes[32];
	//for every surface normal
	//combining all axes into a single array
	for (int j = 0; j < A.size; ++j)
	{
		axes[size++] = A.normals[j];
	}
	for (int j = 0; j < B.size; ++j)
	{
		axes[size++] = B.normals[j];
	}

	CollisionData retval;
	retval.penetrationDepth = INFINITY;
	//for every axis we need to project points onto the axis
	for (int j = 0; j < size; ++j)
	{
		vec2 &axis = axes[j];
		float amin = INFINITY, amax = -INFINITY;
		float bmin = INFINITY, bmax = -INFINITY;

		for (int i = 0; i < A.size; ++i)
		{
			float proj = dot(axis, A.vertices[i]);//scalar projection
			amin = fminf(proj, amin);
			amax = fmaxf(proj, amax);
		}
		for (int i = 0; i < B.size; ++i)
		{
			float proj = dot(axis, B.vertices[i]);//scalar projection
			bmin = fminf(proj, bmin);
			bmax = fmaxf(proj, bmax);
		}

		float pDr, pDl, pD, H;
		pDr = amax - bmin;
		pDl = bmax - amin;

		// axial solution
		pD = fminf(pDr, pDl);
		H = copysignf(1, pDl - pDr);

		if (pD < retval.penetrationDepth)
		{
			retval.penetrationDepth = pD;
			retval.collisionNormal = axis * H;
		}
	}

	return retval;
}
CollisionData HullCollisionGroups(const Hull  A[], unsigned asize, const Hull B[], unsigned bsize)
{
	CollisionData retval;
	retval.penetrationDepth = INFINITY;
	for (int i = 0; i < asize; ++i)
		for (int j = 0; j < bsize; ++j)
		{
			CollisionData temp = HullCollision(A[i], B[j]);

			if (temp.penetrationDepth < retval.penetrationDepth)
				retval = temp;
		}

	return retval;

}

bool CollisionData::result() const
{
	return penetrationDepth >= 0;

}

vec2 CollisionData::MTV() const
{
	return penetrationDepth * collisionNormal;
}

bool CollisionDataSwept::result() const
{
	return entryTime >= 0 && entryTime <= 1;
}
