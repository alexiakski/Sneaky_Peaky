#include "Obst_Medio.hpp"

using namespace Entidades::Personagens;
namespace Entidades::Obstaculos 
{
Obst_Medio::Obst_Medio(float x, float y, float largura, float altura, short int danosidade):
Obstaculo(x, y, largura, altura), danosidade(danosidade)
{
if (pFig != nullptr)
    {
        pFig->setPosition(x, y);
    }
}
Obst_Medio::~Obst_Medio()
{

}

short int Obst_Medio::getDanosidade() const
{
    return danosidade;
}
void Obst_Medio::setDanosidade(short int danosidade)
{
    this->danosidade = danosidade;
}

void Obst_Medio::executar() 
{
    if (pFig != nullptr)
    {
        pFig->setPosition(x, y);
    }
}
void Obst_Medio::salvarDataBuffer()
{

}
void Obst_Medio::salvar()
{

}
void Obst_Medio::obstaculizar (Jogador *pJ)
{
    if (pJ == nullptr)
        return;

    pJ->setNumVidas(pJ->getNumVidas() - danosidade);
    pJ->reposicionar(this->getBounds());
}
}