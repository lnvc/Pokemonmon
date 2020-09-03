#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

using namespace std;

class Pokemon
{
public:
	Pokemon(string name, sf::Texture* texture);
	~Pokemon();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }

private:
	string name;
	// int pokedexNumber;
	// PokemonAnimation pokemonAnimation;
	sf::RectangleShape body;
};

