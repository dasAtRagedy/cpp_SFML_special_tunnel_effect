#include <iostream>
#include <SFML/graphics.hpp>

int main() {
    //setbuf(stdout, nullptr);

    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Toot");
    sf::RectangleShape player(sf::Vector2f(100, 100));
    player.setFillColor(sf::Color::Magenta);
    player.setOrigin(50.0f, 50.0f);

    while(window.isOpen()){
        sf::Event e{};
        while(window.pollEvent(e)){
            switch(e.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    printf("%i %i\n", e.size.width, e.size.height);
                    break;
                case sf::Event::TextEntered:
                    printf("%c", e.text.unicode);
                    break;
            }
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        player.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
