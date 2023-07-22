#pragma once
#include "Vector.h"

class Bounds
{
public:
	Bounds() = delete;
	Bounds(Vector center, Vector extends) : 
		center(center), 
		extends(extends), 
		minPosition(center + (extends * -1)),
		maxPosition(center + extends)
	{	
	
	}

	bool Intersects(const Bounds& otherBounds);

	Vector GetCenter();
	Vector GetExtends();

	Vector center;
	Vector extends;
	Vector minPosition;
	Vector maxPosition;
};

