#include "GameObject.hpp"

GameObject::GameObject() : transform{}, components{}, scripts{}
{

}

void GameObject::Process()
{
	for (int i = 0; i < components.size(); i++)
		components[i]->SetTransform(&transform);
}

void GameObject::AddComponent(Component* c)
{
	components.push_back(c);
}
