#pragma once
class IRenderable
{
	virtual void Render(sf::RenderWindow& renderWindow) = 0;
};