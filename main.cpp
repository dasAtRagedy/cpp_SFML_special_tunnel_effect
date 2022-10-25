#include <iostream>
#include <SFML/graphics.hpp>

int main() {
    setbuf(stdout, NULL);

    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Toot");
    sf::RectangleShape player(sf::Vector2f(100, 100));
    player.setFillColor(sf::Color::Magenta);

    while(window.isOpen()){
        sf::Event e;
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            player.move(0.0f, -0.1f);
        }if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            player.move(-0.1f, 0.0f);
        }if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            player.move(0.0f, 0.1f);
        }if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            player.move(0.1f, 0.0f);
        }

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
