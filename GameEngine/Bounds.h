#pragma once
#include "Vector.h"

class Bounds
{
public:
	Bounds() {};
	Bounds(Vector center, Vector extends) : 
		center(center), 
		extends(extends)
	{	
	
	}

	bool Intersects(Bounds& otherBounds);
	void SetPosition(const Vector& position);
	void SetExtends(const Vector& size);
	Vector GetCenter();
	Vector GetExtends();
	Vector GetMinPosition();
	Vector GetMaxPostition();

private:
	Vector center;
	Vector extends;
	Vector minPosition;
	Vector maxPosition;
};

