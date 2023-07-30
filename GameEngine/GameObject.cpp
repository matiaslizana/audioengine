#include "GameObject.hpp"

GameObject::GameObject(GameObject* parent) : transform{}, components{}, scripts{}, parent{parent}
{
	if (parent != nullptr)
		parent->AddChildren(this);
}

void GameObject::SetPosition(sf::Vector2f position)
{
	transform.SetPosition(position);
	
	for (int i = 0; i < children.size(); i++)
		children[i]->SetPosition(position);
	
	for (int i = 0; i < components.size(); i++)
		components[i]->SetTransform(&transform);
}

sf::Vector2f GameObject::GetPosition()
{
	return transform.GetPosition();
}

void GameObject::Update()
{

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

void GameObject::AddChildren(GameObject* go)
{
	children.push_back(go);
}
