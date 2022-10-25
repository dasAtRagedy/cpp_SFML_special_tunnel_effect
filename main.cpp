#include <iostream>
#include <SFML/graphics.hpp>
#include <math.h>

#define screen_size 512.0f
#define scarcity 0.9f
#define n 50

int main() {
    // setbuf(stdout, nullptr);

    sf::RenderWindow window(sf::VideoMode(screen_size, screen_size), "", sf::Style::None);
    std::vector<sf::RectangleShape> cubes;
    for(int i = 0; i < n; i++){
        sf::RectangleShape cube_prefab(sf::Vector2f(screen_size * pow(scarcity, i+1), screen_size * pow(scarcity, i+1)));
        cube_prefab.setOrigin(screen_size / 2.0f, screen_size / 2.0f);
        cube_prefab.setFillColor(sf::Color::Black);
        cube_prefab.setOutlineColor(sf::Color::Green);
        cube_prefab.setOutlineThickness(1.0f);
        cubes.push_back(cube_prefab);
    }

    while(window.isOpen()){
        sf::Event e{};
        while(window.pollEvent(e)){
            switch(e.type){
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window.close();

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        for(int i = 0; i < n; i++)
            cubes[i].setPosition(
                    (static_cast<float>(mousePos.x) * (1 - pow(scarcity, i+1)) + screen_size / 2),
                    (static_cast<float>(mousePos.y) * (1 - pow(scarcity, i+1)) + screen_size / 2));
        window.clear();
        for(int i = 0; i < n; i++)
            window.draw(cubes[i]);
        window.display();
    }

    return 0;
}
