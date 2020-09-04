#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <nlohmann/json.hpp>

#include "Overworld.h"
#include "Trainer.h"
#include "Pokemon.h"
#include "Collider.h"

using json = nlohmann::json;

// constants
static const float VIEW_WIDTH = 512.0f;
static const float VIEW_HEIGHT = 512.0f;
static const int pokemonCount = 1048;

void ResizeView(const sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = (float)window.getSize().x / (float)window.getSize().y;
    // literally just resize based on current size
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

std::vector<std::string> ListFiles() {
    std::vector<std::string> v, ans;

    for (int i = 97; i < 122; i++) {
        for (int j = 97; j <= 122; j++) {
            std::string temp = "";
            temp.push_back(char(i));
            temp.push_back(char(j));
            v.push_back(temp);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        ans.push_back("x" + v[i]);
    }
    for (int i = 0; i < v.size(); i++) {
        if ("xza" + v[i] == "xzapi")
            break;
        ans.push_back("xza" + v[i]);
    }
    return ans;
}
int main()
{
    // seed rand
    srand(time(0));
    std::vector<std::string> v = ListFiles();


    //std::ifstream inp("pokemon_json/xaa.json");
    //json j;
    //inp >> j;
    //std::cout << j["name"];

    sf::Music mainTheme;
    mainTheme.openFromFile("audio/dreamyard.ogg");
    mainTheme.setLoop(true);
    mainTheme.play();

    sf::RenderWindow window(sf::VideoMode(512, 512), "Pokemonmon", sf::Style::Close | sf::Style::Resize);

    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
    
    // textures
    sf::Texture grassTexture, treeTexture, trainerTexture, pokemonTexture;
    grassTexture.loadFromFile("textures/grass-tiles-2-small.png");
    treeTexture.loadFromFile("textures/tree2-final.png");
    trainerTexture.loadFromFile("textures/trainer.png");
    pokemonTexture.loadFromFile("pokemon/oshawott_front.png");
    Overworld grass(&grassTexture, sf::Vector2f(24.0f, 24.0f), sf::Vector2u(6, 2), true);
    Overworld tree(&treeTexture, sf::Vector2f(96.0f, 96.0f), sf::Vector2u(1, 1), false);
    grass.Populate();
    tree.Populate();
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

        // grass.Populate();
        trainer.Walk(deltaTime);
        Collider trainerCollider = trainer.GetCollider();
        pokemon.GetCollider().CheckCollision(trainerCollider, 0.0f);


        view.setCenter(trainer.GetPosition());

        window.clear();
        window.setView(view);

        grass.Draw(window);
        trainer.Draw(window);   
        tree.Draw(window);
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
