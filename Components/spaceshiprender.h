#pragma once
#include "Transform.h"

class ShipRender
{
public:
	ShipRender();
	
	void drawship(const Transform &ShipTransform, const mat3 &camera);
};