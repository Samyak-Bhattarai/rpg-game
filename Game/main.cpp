#include<iostream>
#include<SFML/Graphics.hpp>

int main()
{
    float circleSize = 50.0f;

    //Anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //Creating a window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG game", sf::Style::Default, settings);

    //Texture Loading
    sf::Texture playerTexture;
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    sf::Sprite playerSprite;

    if (enemyTexture.loadFromFile("assets/Enemy/Textures/spritesheet.png")) {
        enemySprite.setTexture(enemyTexture);
        int xIndex = 1;
        int yIndex = 2;
        enemySprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        enemySprite.setScale(sf::Vector2f(3, 3));
        std::cout << "Texture Loaded" << std::endl;
    }

    if (playerTexture.loadFromFile("assets/Player/Textures/spritesheet.png")) {
        playerSprite.setTexture(playerTexture);
        int xIndex = 0;
        int yIndex = 0;
        playerSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
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
        sf::Vector2f position = playerSprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
          
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        }
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.draw(enemySprite);
        window.display();
    }
    return 0;
}