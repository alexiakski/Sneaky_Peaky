#include "Projetil.hpp"
#include "Personagem.hpp"

Projetil::Projetil(float x, float y, float largura, float altura, int dano) :
Entidade(x, y, largura, altura), ativo(true), dano(dano)
{

}
Projetil::~Projetil()
{

}

bool Projetil::getAtivo() const
{
    return ativo;
}
void Projetil::setAtivo(bool ativo)
{
    this->ativo = ativo;
}
int Projetil::getDano() const
{
    return dano;
}

void Projetil::colidir(Entidade *pEnt)
{
    if (pEnt == nullptr || !ativo)
        return;

    Personagem *pPers = dynamic_cast<Personagem*>(pEnt);

    if (pPers != nullptr)
    {
        pPers->setNumVidas(pPers->getNumVidas() - dano);

        ativo = false;
    }
}
void Projetil::mover()
{
    if(ativo)
    {
        x += 5;

        if(pFig != nullptr )
            pFig->setPosition(x, y);
    }
}

void Projetil::executar()
{
    if(ativo)
        mover();
}
void Projetil::salvar()
{

}
void Projetil::salvarDataBuffer()
{
    
}
