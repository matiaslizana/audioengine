#pragma once

#include "Transform.h"
#include "GameObject.h"

class GameObject;

class Component
{
protected:
	std::shared_ptr<GameObject> gameObject;

public:
	Component(std::shared_ptr<GameObject> gameObject);
	virtual ~Component() = default;

	virtual void SetTransform(Transform* t) {}
};