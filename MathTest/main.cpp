#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.0.h"
#include "mat2.h"
#include "vec3.0.h"
#include "Mat3.h"
#include "flops.h"
#include <cfloat>
#include <cmath>
#include "shape.h"
#include "collision.h"
int main()
{

	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 0,1 } != vec2{ 0,0 }));
	assert(((vec2{ 0,0 } -= vec2{ 0,0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } += vec2{ 0,0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } -vec2{ 0, 0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } +vec2{ 0, 0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } / 1) == vec2{ 0, 0 }));
	assert(((vec2{ 0,0 } *1) == vec2{ 0, 0 }));
	assert(magnitude(vec2{ 0,1 }) == 1);
	assert((normal(vec2{ 0,1 }) == vec2{ 0,1 }));
	assert(!fequal(1, 0.00001));

	vec2 N = normal(vec2{ 1,1 });
	assert(fequal(magnitude(N), 1));

	// Dot product with an AXIS should give us the coordinate value
	// along that axis.
	assert(fequal(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequal(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));

	// Anglebetween the X-Axis should give us the angle of the vector.
	assert(fequal(angleBetween(vec2{ 0,1 }, vec2{ 0,1 }),
		deg2rad(0)));
	assert(fequal(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }),
		deg2rad(45)));
	assert(fequal(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }),
		angle(vec2{ 1,1 })));

	// Angle of 0 should be the X-Axis
	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));

	// Testing cross product
	// Ensure that the Z-axis results from
	// crossing the X-axis and Y-Axis
	assert((vec3{ 0,0 } == vec3{ 0,0 }));
	assert((vec3{ 0,1 } != vec3{ 0,0 }));
	assert(((vec3{ 0,0 } -= vec3{ 0,0 }) == vec3{ 0,0 }));
	assert(((vec3{ 0,0 } += vec3{ 0,0 }) == vec3{ 0,0 }));
	assert(((vec3{ 0,0 } -vec3{ 0, 0 }) == vec3{ 0,0 }));
	assert(((vec3{ 0,0 } +vec3{ 0, 0 }) == vec3{ 0,0 }));
	assert(((vec3{ 0,0 } / 1) == vec3{ 0, 0 }));
	assert(((vec3{ 0,0 } *1) == vec3{ 0, 0 }));
	assert(magnitude(vec3{ 0,1 }) == 1);


	assert((cross(vec3{ 1,0,0 }, vec3{ 0,1,0 })
		== vec3{ 0,0,1 }));

	// reversing the operands will give me the back-facing vector.
	assert(((cross(vec3{ 0,1,0 }, vec3{ 1,0,0 })
		== vec3{ 0,0,-1 })));

	assert(fequal(lerp(.23, 124, 0), .23));
	assert(fequal(lerp(.23, 124, 1), 124));

	assert(fequal(quadBezier(15, 40, 21, 0), 15));
	assert(fequal(quadBezier(15, 40, 21, 1), 21));



	assert(fequal(hermiteSpline(15, 40, 21, 10, 0), 15));
	assert(fequal(hermiteSpline(15, 40, 21, 10, 1), 21));

	float yeah = cardinalSpline(15, 40, 21, .1f, 1);
	assert(fequal(cardinalSpline(15, 40, 21, .2f, 0), 15));
	assert(fequal(cardinalSpline(15, 40, 21, .1f, 1), 21));


	assert(fequal(catRomSpline(15, 40, 21, 0), 15));
	assert(fequal(catRomSpline(15, 40, 21, 1), 21));

	assert((mat2{ 1,2,3,4 } == mat2{ 1,2,3,4 }));
	assert((mat2{ 1,2,3,4 } != mat2{ 0,1,2,3 }));

	assert(fequal(determinant(mat3{ 1,2,3,4,5,6,7,8,9 }), 0.0f));
//	assert((inverse(mat3{ 2,4,5,6,7,8,9,10,11 }) == mat3{ -3, 6,-3,6,-23, 14,-3,16,-10 } *(1 / 3)));
	
	mat3 mi3 = mat3Identity();
	mat3 testing = mat3{ 1,0,2,0,3,0,4,0,0 };
	assert(inverse(testing)*testing == mi3);


	vec3 j = { 2,5,1 };

	assert((scale(5, 1) * j == vec3{ 10,5,1 }));
	//assert((rotation(deg2rad(90))*j == vec3{ -5,2,1 }));
	//assert((translate(0, 3)*j == vec3{ 2,8,1 }));
	
	//assert((rotation(deg2rad(-90))* translate(10, 0) * vec3 { 0, 0, 1 }) == (vec3{ 0,-10,1 }));
	
	assert((rotation(deg2rad(-90)) * translate(10, 0) * rotation(deg2rad(45)) * translate(4, 0) * rotation(deg2rad(45)) * translate(6, 4) * translate(-6, 0) * vec3 { 0, 0, 1 } == vec3{ 2 * sqrtf(2), -6 - 2 * sqrtf(2),1 }));
	Circle c = { 0,0,5 };

	assert((translate(4, 0) * c == Circle{ 4,0,5 }));
	assert((scale(2, 1) * c == Circle{ 0,0,10 }));
	assert((scale(2, 2) * c == Circle{ 0,0,10 }));
	assert((scale(1, 2) * c == Circle{ 0,0,10 }));

	assert((scale(-1, 1) * c == Circle{ 0,0,5 }));
	assert((rotation(45) * c == Circle{ 0,0,5 }));

	AABB testA = { 1,2,3,4 };

	assert((testA.min() == vec2{-2,-2 }));
	assert((testA.max() == vec2{ 4,6 }));

	assert(collisionDetection1D(0, 2, 1, 3).result == true);
	assert(collisionDetection1D(0, 2, 1, 3).penetrationDepth == 1);

	assert(sweptDetection1D(0, 1, 5, 3, 4, 0).entryTime == .4f);
	

	assert(sweptDetection1D(0, 1, -5, 3, 4, 10).result() == false);
	
	AABB A = { 0,0,2,4 },
		 B = { 2,2,2,4 };
	assert(boxCollision(A, B).penetrationDepth == 2);
	assert((boxCollision(A, B).collisionNormal == vec2{  1, 0 }));
	assert((boxCollision(B, A).collisionNormal == vec2{ -1, 0 }));

	AABB As = { 0,0, 1,1 };
	AABB Bs = { 0,10, 1,1 };




	vec2 verts[] = { {0,1},{1,1},{1,0},{0,0} };
	vec2 verts2[] = { { -1,-1 },{ -1,1 },{ 0,0 } };

	Hull myHull(verts, 4);
	Hull otherHull(verts2, 3);

	assert((myHull.normals[0] == vec2{ 0,1 }));
	assert((myHull.normals[1] == vec2{ 1,0 }));
	assert((myHull.normals[2] == vec2{ 0,-1 }));
	assert((myHull.normals[3] == vec2{ -1,0 }));

	Hull tHull = translate(1, 0) * myHull;
	assert((tHull.vertices[0] == vec2{ 1,1 }));
	assert((tHull.vertices[1] == vec2{ 2,1 }));
	assert((tHull.vertices[2] == vec2{ 2,0 }));
	assert((tHull.vertices[3] == vec2{ 1,0 }));

	//collision
	assert(fequal(HullCollision(myHull, otherHull).penetrationDepth, 0));
	assert(fequal(HullCollision(otherHull, tHull).penetrationDepth, -1));

	getchar();
	return 0;
}