#include "stdafx.hpp"
#include "Jogador.hpp"

Jogador::Jogador(float x, float y, int largura, int altura) : Personagem(x, y, largura, altura, 3)//3?
{
    pontos = 0;
}

Jogador::~Jogador()
{

}

void Jogador::colidir(Inimigo* pIn)
{
    if (pIn == nullptr)
        return;

    sf::FloatRect boundsJogador = getBounds();  
    sf::FloatRect boundsInimigo = pIn->getBounds();

    float pesJogador = boundsJogador.top + boundsJogador.height;
    float cabecaInimigo = boundsInimigo.top;
   
    if (pesJogador - velocidadeY <= cabecaInimigo + 5 && velocidadeY > 0)
    {
        pIn->setNumVidas(pIn->getNumVidas() - 1);

        velocidadeY = -10; 
    }
    else
    {
        this->setNumVidas(this->getNumVidas() - 1);
    }
}
void Jogador::sofrerAtaque(int dano)
{
    num_vidas-=dano;
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

    if (pFig != nullptr) {
        pFig->setPosition(x, y);
    }
}

void Jogador::executar()
{
   mover();
}