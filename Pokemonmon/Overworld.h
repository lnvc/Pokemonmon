#pragma once
#include <vector>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Overworld
{
public:
	Overworld(sf::Texture* texture, sf::Vector2f size, sf::Vector2u tileCount, bool isGround);
	~Overworld();
	
	void Populate();
	void Draw(sf::RenderWindow& window);

private:
	sf::RenderWindow window;
	sf::IntRect uvRect;
	sf::Vector2f size;
	sf::RectangleShape tile;
	std::vector<sf::RectangleShape> tiles;
	bool isGround;
};

