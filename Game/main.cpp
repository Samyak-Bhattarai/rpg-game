#include<SFML/Graphics.hpp>

int main()
{
    float circleSize = 50.0f;

    //Creating a window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(600, 800), "RPG game", sf::Style::Default, settings);

    sf::CircleShape circle(circleSize);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(sf::Vector2f(100, 50));

    sf::RectangleShape rectangle(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(sf::Vector2f(200, 200));
    rectangle.setOrigin(rectangle.getSize()/2.0f);
    rectangle.setRotation(45);

    sf::CircleShape triangle(80.0f, 3);
    triangle.setFillColor(sf::Color::Red);
    triangle.setPosition(sf::Vector2f(300, 400));
    

 
    //Creating a game loop
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            window.clear(sf::Color::Black);
            window.draw(circle);
            window.draw(rectangle);
            window.draw(triangle);
            window.display();
        }
    }
    return 0;
}