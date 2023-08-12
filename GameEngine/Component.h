#pragma once

#include "Transform.h"
#include "GameObject.h"
#include <memory>

class GameObject;

class Component
{
protected:
	std::shared_ptr<GameObject> gameObject;

public:
	Component(std::shared_ptr<GameObject> gameObject);

	virtual void SetTransform(Transform& t) {}
	virtual void Update() {}
};