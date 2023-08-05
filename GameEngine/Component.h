#pragma once

#include "Transform.h"
#include "GameObject.hpp"

class GameObject;

class Component
{
protected:
	GameObject* gameObject;

public:
	Component(GameObject* gameObject);

	virtual void SetTransform(Transform* t) {}
};