#include "Gerenciador_Grafico.hpp"
#include "Ente.hpp"

Gerenciador_Grafico::Gerenciador_Grafico() : janela(sf::VideoMode(800,600), "Sneaky Peaky")
{
    janela.setFramerateLimit(60);
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{

}

bool Gerenciador_Grafico::estaAberta()
{
    return janela.isOpen();
}

void Gerenciador_Grafico::processarEventos()
{
    sf::Event evento;

    while (janela.pollEvent(evento))
    {
        if(evento.type == sf::Event::Closed)
            janela.close();
    }
}
void Gerenciador_Grafico::limpar()
{
    janela.clear();
}

void Gerenciador_Grafico::desenhar(Ente* pE)
{
    if (pE != nullptr)
        janela.draw(*pE->getFigura());
}

void Gerenciador_Grafico::mostrar()
{
    janela.display();
}