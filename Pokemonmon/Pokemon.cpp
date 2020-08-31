#include "Pokemon.h"

Pokemon::Pokemon(string name, sf::Texture* texture)
{
	this->name = name;
	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setPosition(sf::Vector2f(80.0f, 80.0f));
	body.setOrigin(sf::Vector2f(25.0f, 25.0f));
	body.setTexture(texture);
}

Pokemon::~Pokemon()
{
}

void Pokemon::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
