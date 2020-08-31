#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Trainer
{
public:
	Trainer(sf::Texture* texture, sf::Vector2u spriteCount, float switchTime, float speed);
	~Trainer();

	void Walk(float deltaTime);
	void Draw(sf::RenderWindow& window);
	
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int col;
	float speed;
};

