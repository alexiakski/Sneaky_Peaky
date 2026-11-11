#include "stdafx.hpp"
#include "Samurai.hpp"

Chefao::Chefao(float x, float y) : Inimigo(x, y, 100, 100, 1, 5)
{
    setTextura("assets/SamuraiAzul.png", sf::IntRect(0, 0, 88, 88));//só a primeira pose
}

Chefao::~Chefao()
{

}

/*short int Chefao::getNivelMaldade()
{
    return nivel_maldade;
}

void Chefao::setNivelMaldade(short int nivel_maldade)
{
    this->nivel_maldade = nivel_maldade;
}

void Chefao::executar()
{

}

void Chefao::salvarDataBuffer()
{

}*/

void Chefao::salvar()
{

}

void Chefao::danificar (Jogador* pJog)
{
    if (pJog == nullptr)
        return;

    int dano = 2 * nivel_maldade;
    int vidasAtuais = pJog->getNumVidas();
    pJog->setNumVidas(vidasAtuais - dano);
    
    //pJog->reposicionar(this->getBounds());
}