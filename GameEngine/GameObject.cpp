#include "GameObject.hpp"

GameObject::GameObject() : transform{}, components{}, scripts{}
{

}

void GameObject::SetPosition(sf::Vector2f position)
{
	transform.SetPosition(position);
}

sf::Vector2f GameObject::GetPosition()
{
	return transform.GetPosition();
}

void GameObject::Update()
{
	for (int i = 0; i < components.size(); i++)
		components[i]->SetTransform(&transform);
}

void GameObject::AddComponent(Component* c)
{
	c->SetTransform(&transform);
	components.push_back(c);
}

void GameObject::AddGameScript(GameScript* gs)
{
	scripts.push_back(gs);
}