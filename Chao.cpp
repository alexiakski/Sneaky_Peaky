#include "stdafx.hpp"
#include "Chao.hpp"
#include "Personagem.hpp"
#include "Gerenciador_Grafico.hpp"

Chao::Chao(float x, float y, float largura, float altura, sf::IntRect recorte) : Entidade(x, y, largura, altura)
{
    sf::Texture* pTex = pGG->carregarTextura("assets/TilesetField.png", recorte);//textura do chão
    if (pTex != nullptr)
    {
        pTex->setRepeated(true);//azulejo
        pFig->setTexture(pTex);
        pFig->setTextureRect(sf::IntRect(0,0,largura,altura));
    }
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