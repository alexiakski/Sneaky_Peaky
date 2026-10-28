#include "stdafx.hpp"

#include <SFML/Graphics.hpp>

namespace trabalho_tec_prog
{
    class Ente{};

    namespace Entidades
    {
        class Entidade : public Ente{};

        namespace Obstaculos
        {
            class Obstaculo : public Entidade{};
        }
    }
    
    namespace Gerenciadores
    {
        class Gerenciador_Grafico{};
        class Gerenciador_Colisoes{};
    }
}

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
    }*/

    return 0;
}