#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u spriteCount, float switchTime)
{
	this->spriteCount = spriteCount;
	this->switchTime = switchTime;

	totalTime = 0.0f;
	currentSprite.y = 0;

	uvRect.width = texture->getSize().x / (float)spriteCount.x;
	uvRect.height = texture->getSize().y / (float)spriteCount.y;
}

Animation::~Animation()
{
}

void Animation::Update(int col, float deltaTime)
{
	currentSprite.x = col;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		// switch to next frame
		totalTime -= switchTime;
		currentSprite.y++;

		if (currentSprite.y >= spriteCount.y)
			currentSprite.y = 0;
	}

	// y = what point in plane, uvRect.height = height of one rectangle
	uvRect.top = currentSprite.y * uvRect.height;
	uvRect.left = currentSprite.x * uvRect.width;

}

void Animation::Idle(int col)
{
	currentSprite.x = col;
	currentSprite.y = 0;
	uvRect.top = currentSprite.y * uvRect.height;
	uvRect.left = currentSprite.x * uvRect.width;
}