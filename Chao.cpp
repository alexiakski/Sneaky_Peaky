#include "stdafx.hpp"
#include "Chao.hpp"
#include "Personagem.hpp"

Chao::Chao(float x, float y, float largura, float altura) : Entidade(x, y, largura, altura)
{
    if (pFig != nullptr)
        pFig->setFillColor(sf::Color(110, 70, 40));//qual textura eu coloco mds
}

Chao::~Chao()
{

}

void Chao::sustentar(Personagem* pP)
{
    if (pP != nullptr)
        pP->reposicionar(getBounds());
}

void Chao::executar()
{

}

void Chao::salvar()
{
    //Implementar no requisito 10
}