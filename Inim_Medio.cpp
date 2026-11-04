#include "stdafx.hpp"
#include "Inim_Medio.hpp"

Inim_Medio::Inim_Medio(float x, float y) : Inimigo(x, y, 56, 56, 2, 2)
{
    setTextura("assets/TenguAzul.png", sf::IntRect(0, 0, 68, 68));//só a primeira pose
}

Inim_Medio::~Inim_Medio()
{

}

void Inim_Medio::danificar(Jogador* pJog)
{

}

void Inim_Medio::salvar()
{

}