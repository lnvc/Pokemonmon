#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u spriteCount, float switchTime);
	~Animation();

	void Update(int col, float deltaTime);
	void Idle(int col);

public:
	sf::IntRect uvRect;
private:
	sf::Vector2u spriteCount;
	sf::Vector2u currentSprite;

	float totalTime;
	float switchTime;
};

