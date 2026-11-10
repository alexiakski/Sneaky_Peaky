#include "stdafx.hpp"
#include "Chefao.hpp"

Chefao::Chefao(float x, float y) : Inimigo(x, y, 100, 100, 1, 5)
{
    setTextura("assets/SamuraiAzul.png", sf::IntRect(0, 0, 88, 88));//só a primeira pose
}

Chefao::~Chefao()
{

}

void Chefao::danificar (Jogador* pJog)
{

}

void Chefao::salvar()
{

}