#include "stdafx.hpp"
#include "Jogo.hpp"

#include <SFML/Graphics.hpp>

int main()
{
    /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }teste SFML*/

    Jogo jogo;
    jogo.executar();

    return 0;
}

//para compilar e rodar: ctrl + shift + b
//para só compilar: ctrl + shift + p