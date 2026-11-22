#include "stdafx.hpp"
#include "Inim_DuendeAzul.hpp"

namespace Entidades::Personagens 
{

Inim_DuendeAzul::Inim_DuendeAzul(float x, float y) : Inimigo(x, y, 60, 60, 2, 2)
{
    setTextura("assets/TenguAzul.png", sf::IntRect(0, 0, 68, 68));//só a primeira pose
}

Inim_DuendeAzul::~Inim_DuendeAzul()
{

}

void Inim_DuendeAzul::danificar(Jogador* pJog)
{

}

void Inim_DuendeAzul::salvar()
{

}
}