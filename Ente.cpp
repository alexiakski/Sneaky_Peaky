#include "stdafx.hpp"
#include "Ente.hpp"
#include "Gerenciador_Grafico.hpp"

int Ente::cont = 0;
Gerenciador_Grafico* Ente::pGG = nullptr;

Ente::Ente() : id(cont++), pFig(new sf::RectangleShape())
{
    
}

Ente::~Ente()
{
    delete pFig;
    pFig = nullptr;
}

int Ente::getId()
{
    return id;
}

sf::RectangleShape* Ente::getFigura()
{
    return pFig;
}

void Ente::desenhar()
{
    if (pGG != nullptr)
        pGG->desenhar(this);
}

void Ente::setGG(Gerenciador_Grafico *pG)
{
    pGG = pG;
}

void Ente::setTextura(const std::string& caminho, sf::IntRect recorte)
{
    if (pGG == nullptr)
        return;

    sf::Texture* pTex = pGG->carregarTextura(caminho);//escolhe a figura

    if (pTex == nullptr)
        return;

    pFig->setTexture(pTex);//set a figura

    if (recorte.width > 0)
        pFig->setTextureRect(recorte);
}