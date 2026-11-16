#include "stdafx.hpp"
#include "Samurai.hpp"

Chefao::Chefao(float x, float y) : Inimigo(x, y, 100, 50, 1, 5)
{
    setTextura("assets/SamuraiAzul.png", sf::IntRect(0, 0, 96, 48));//só a primeira pose
}

Chefao::~Chefao()
{

}

void Chefao::salvar()
{

}

void Chefao::danificar (Jogador* pJog)
{
    if (pJog == nullptr)
        return;

    *pJog -= 2 * nivel_maldade;

    /*int dano = 2 * nivel_maldade;
    int vidasAtuais = pJog->getNumVidas();
    pJog->setNumVidas(vidasAtuais - dano);*/
    
    //pJog->reposicionar(this->getBounds());
}