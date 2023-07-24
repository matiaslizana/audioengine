#pragma once
#include "Transform.h"

class Component
{
public:
	virtual void SetTransform(Transform* t) = 0;
};