#include "Trainer.h"

Trainer::Trainer(sf::Texture* texture, sf::Vector2u spriteCount, float switchTime, float speed) :
	animation(texture, spriteCount, switchTime)
{
	this->speed = speed;
	col = 0;

	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
	body.setOrigin(50.0f, 50.0f);
}

Trainer::~Trainer()
{

}

void Trainer::Walk(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed * deltaTime;

	if (!(movement.x == 0.0f && movement.y == 0.0f)) {
		if (movement.x > 0.0f) {
			col = 3;
		}
		else if (movement.x < 0.0f) {
			col = 1;
		}
		else if (movement.y > 0.0f) {
			col = 0;
		}
		else {
			col = 2;
		}
		animation.Update(col, deltaTime);
	}
	else {
		animation.Idle(col);
	}

	body.setTextureRect(animation.uvRect);
	body.move(movement);

}

void Trainer::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

