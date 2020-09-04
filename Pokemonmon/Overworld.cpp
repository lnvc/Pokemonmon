#include "Overworld.h"

Overworld::Overworld(sf::Texture* texture, sf::Vector2f size, sf::Vector2u tileCount, bool isGround) 
{
	tile.setSize(size);
	tile.setTexture(texture);
	this->size = size;
	tile.setOrigin(size.x / 2.0f, size.y / 2.0f);
	if (size.x != 96.0f) {
		uvRect.width = texture->getSize().x / (float)tileCount.x;
		uvRect.height = texture->getSize().y / (float)tileCount.y;
	}
	this->isGround = isGround;
}

Overworld::~Overworld()
{
}

void Overworld::Populate()
{
	// if ground
	if (isGround) {
		// ground
		for (float i = 0.0f; i < 1920.0f; i += size.x) {
			for (float j = 0.0f; j < 1920.0f; j += size.x) {
				unsigned int l = rand() % 6, t;
				if (l == 5)
					t = 0;
				else
					t = rand() % 2;
				uvRect.left = l * uvRect.width;
				uvRect.top = t * uvRect.height;
				tile.setPosition(i, j);
				tile.setTextureRect(uvRect);
				tiles.push_back(tile);
			}
		}
	}
	// else building
	else {
		// tree
		for (float i = 0.0f; i < 1920.0f; i += size.x) {
			for (float j = 0.0f; j < 1920.0f; j += size.x) {
				if (rand() % 4 == 1) {
					tile.setPosition(i, j);
					tiles.push_back(tile);
				}
			}
		}
	}
}

void Overworld::Draw(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < tiles.size(); i++) {
		window.draw(tiles[i]);
	}
}
