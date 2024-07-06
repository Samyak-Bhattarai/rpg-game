#include<iostream>
#include<SFML/Graphics.hpp>

int main()
{
    float circleSize = 50.0f;

    //Anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //Creating a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG game", sf::Style::Default, settings);

    //Texture Loading
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("assets/Player/Textures/spritesheet.png")) {
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(256, 128, 64, 64));
        playerSprite.setScale(sf::Vector2f(3, 3));
        std::cout << "Texture Loaded" << std::endl;
    }
    else {
        std::cout << "Failed Loading the texture" << std::endl;
    }
 

 
    //Creating a game loop
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        }
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
    }
    return 0;
}