#pragma once
class IRenderable
{
public:
	virtual void Render(sf::RenderWindow& renderWindow) = 0;
};