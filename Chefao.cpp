#include "Chefao.hpp"

Chefao::Chefao(float x, float y, float largura, float altura, short int nivel_maldade):
Entidade(x, y, largura, altura), nivel_maldade(nivel_maldade)
{

}
#include "stdafx.hpp"
#include "Chefao.hpp"

Chefao::Chefao(float x, float y) : Inimigo(x, y, 100, 100, 1, 5)
{
    setTextura("assets/SamuraiAzul.png", sf::IntRect(0, 0, 88, 88));//só a primeira pose
}

Chefao::~Chefao()
{

}

short int Chefao::getNivelMaldade()
{
    return nivel_maldade;
}
void Chefao::setNivelMaldade(short int nivel_maldade)
{
    this->nivel_maldade = nivel_maldade;
}

virtual void Chefao::executar()
{

}
void Chefao::salvarDataBuffer()
{

}
virtual void Chefao::salvar()
{

}
void Chefao::danificar (Jogador* pJog)
{
    if (pJog == nullptr)
        return;

    int dano = 2 * nivel_maldade;
    int vidasAtuais = pJog->getNumVidas();
    pJog->setNumVidas(vidasAtuais - dano);
    
    pJog->reposicionar(this->getBounds());
}