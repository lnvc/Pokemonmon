#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Animation.h"

using namespace std;

class Pokemon
{
public:
	Pokemon(string name, sf::Texture* texture);
	~Pokemon();

	void Draw(sf::RenderWindow& window);

private:
	string name;
	//int pokedexNumber;
	// PokemonAnimation pokemonAnimation;
	sf::RectangleShape body;
};

