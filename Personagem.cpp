#include "stdafx.hpp"
#include "Personagem.hpp"

Personagem::Personagem(float x, float y, int largura, int altura, int num_vidas) : Entidade(x, y, largura, altura), num_vidas(num_vidas), velocidadeY(0), chao(false)
{

}

Personagem::~Personagem()
{

}

int Personagem::getNumVidas()
{
    return num_vidas;
}

void Personagem::setNumVidas(int num_vidas)
{
    this->num_vidas = num_vidas;
}

void Personagem::salvarDataBuffer()
{
    //Implentar no requisito 10
}

void Personagem::aplicarGravidade()
{
    velocidadeY += 0.5f;//aceleração

    if (velocidadeY > 12)
        velocidadeY = 12;//velocidade máxima

    y += velocidadeY;
    chao = false;             //o chão volta a pôr true se estiver encostado
}

void Personagem::reposicionar(const sf::FloatRect& r)
{
    sf::FloatRect eu = getBounds();

    y = r.top - eu.height;      //pés no topo
    velocidadeY = 0;
    chao = true;

    if (pFig != nullptr)
        pFig->setPosition(x, y);
}