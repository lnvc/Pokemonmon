#include <iostream>
#include <SFML/Graphics.hpp>
#include "Trainer.h"
#include "Pokemon.h"
#include "Collider.h"


static const float VIEW_HEIGHT = 512.0f;
void ResizeView(const sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = (float)window.getSize().x / (float)window.getSize().y;
    // literally just resize based on current size
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Pokemonmon", sf::Style::Close | sf::Style::Resize);

    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    sf::Texture trainerTexture, pokemonTexture;
    trainerTexture.loadFromFile("gfx/trainer.png");
    pokemonTexture.loadFromFile("images/oshawott_front.png");
    Trainer trainer(&trainerTexture, sf::Vector2u(4, 4), 0.3f, 100.0f);
    Pokemon pokemon("Oshawott", &pokemonTexture);

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type)
            {
            case sf::Event::Resized:
                ResizeView(window, view);
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        trainer.Walk(deltaTime);
        Collider trainerCollider = trainer.GetCollider();
        pokemon.GetCollider().CheckCollision(trainerCollider, 0.0f);

        view.setCenter(trainer.GetPosition());

        window.clear();
        window.setView(view);

        trainer.Draw(window);   
        pokemon.Draw(window);

        window.display();
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
