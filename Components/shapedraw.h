#pragma once
#include "shape.h"
#include "Transform.h"

void drawCircle(const Circle &C, unsigned color);
void drawAABB(const AABB &B, unsigned color);
void drawPlane(const Plane & p, unsigned color);
void drawHull(const Hull & H, unsigned color);