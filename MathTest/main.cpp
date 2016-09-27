#include <cassert>
#include <cstdio>
#include "Test.h"
#include <cmath>
#include "vec2.0.h"
#include "vec3.0.h"
int main()
{

	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 0,0 } != vec2{ 0,0 }));
	assert(((vec2{ 0,0 } -= vec2{ 0,0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } += vec2{ 0,0 }) == vec2{ 0,0 }));
	assert((vec2{ 0,0 } -{ 0, 0.f }));
	assert((vec2{ 0,0 } +{ 0, 0 }));
	assert((vec2{ 0,0 } *{ 0, 0 }));
	assert((vec2{ 0,0 } / { 0, 0 }));
	assert(magnitude(vec2{ 0,1 }) == 1);

	getchar();
	return 0;
}