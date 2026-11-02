#include "stdafx.hpp"
#include "Jogador.hpp"

Jogador::Jogador(float x, float y, int largura, int altura) : Personagem(x, y, largura, altura, 3)//3?
{
    pontos = 0;
}

Jogador::~Jogador()
{

}

void Jogador::salvar()
{
    // Implementar no requisito 10
}

void Jogador::mover()
{
    float velocidade = 3;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        y -= velocidade;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        y += velocidade;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        x -= velocidade;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        x += velocidade;

    pFig->setPosition(x, y);
}

void Jogador::executar()
{
   mover();
}