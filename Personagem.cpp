#include "stdafx.hpp"
#include "Personagem.hpp"

Personagem::Personagem(float x, float y, int largura, int altura, int num_vidas) : Entidade(x, y, largura, altura), num_vidas(num_vidas)
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
