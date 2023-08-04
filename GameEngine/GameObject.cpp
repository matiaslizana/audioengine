#include "GameObject.hpp"

GameObject::GameObject(const std::string& name, const std::shared_ptr<GameObject>& parent) :
	components{}, parent{parent}, localTransform{}, name{name}, transform{}
{
	if (parent != nullptr)
		parent->AddChildren(std::shared_ptr<GameObject>(this));
}

GameObject::~GameObject()
{
	//TODO: This is breaking on deleting scripts
	//for (int i = 0; i < components.size(); i++)
	//	delete(components[i]);

	//for (int i = 0; i < scripts.size(); i++)
	//	delete(scripts[i]);
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
		component->SetTransform(&transform);
}

sf::Vector2f GameObject::GetPosition()
{
	return transform.GetPosition();
}

void GameObject::Update()
{

}

void GameObject::AddComponent(const std::shared_ptr<Component>& c)
{
	c->SetTransform(&transform);
	components.push_back(c);
}

void GameObject::AddChildren(const std::shared_ptr<GameObject>& go)
{
	children.push_back(go);
}
