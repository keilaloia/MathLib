#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.0.h"
#include "vec3.0.h"
#include "flops.h"
#include <cfloat>
#include <cmath>

int main()
{

	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 0,1 } != vec2{ 0,0 }));
	assert(((vec2{ 0,0 } -= vec2{ 0,0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } += vec2{ 0,0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } -vec2{ 0, 0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } +vec2{ 0, 0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } / 1) == vec2{ 0, 0 }));
	assert(((vec2{ 0,0 } * 1) == vec2{ 0, 0 }));
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
	getchar();
	return 0;
}