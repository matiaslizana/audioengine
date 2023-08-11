#include "GameObject.h"

GameObject::GameObject(const std::string& name) :
	components{}, children{}, localTransform {}, name{ name }, transform{}
{

}

//Updates localTransform, transform and children transform
void GameObject::SetPosition(sf::Vector2f localPosition)
{
	localTransform.SetPosition(localPosition);
	SetTransform();

	for (const auto& child : children)
		child->SetTransform();	
}

//Updates transform position from parent
void GameObject::SetTransform()
{
	if (parent == nullptr)
		transform.SetPosition(localTransform.GetPosition());
	else
		transform.SetPosition(parent->GetPosition() + localTransform.GetPosition());
	
	for (const auto& component : components)
		component->SetTransform(transform);
}

sf::Vector2f GameObject::GetPosition()
{
	return transform.GetPosition();
}

void GameObject::Update()
{
	for (const auto& component : components)
		component->Update();
}

void GameObject::AddComponent(std::shared_ptr<Component> c)
{
	c->SetTransform(transform);
	components.push_back(c);
}

void GameObject::AddChildren(std::shared_ptr<GameObject> go)
{
	children.push_back(go);
}

void GameObject::SetParent(std::shared_ptr<GameObject> parent)
{
	this->parent = parent;
}
