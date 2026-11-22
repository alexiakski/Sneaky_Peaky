#include "Projetil.hpp"
#include "Personagem.hpp"

using namespace Entidades::Personagens;

namespace Entidades 
{

Projetil::Projetil(float x, float y, float largura, float altura, int dano) :
Entidade(x, y, largura, altura), dano(dano)
{
    setTextura ("assets/Shuriken.png");
}
Projetil::~Projetil()
{

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
        *pPers -= dano;
        
        ativo = false;
    }
}
void Projetil::mover()
{
    if(ativo)
    {
        x += 4;//velocidade

        if (x < -largura || x > 800 || y > 600)//saiu da janela
            ativo = false;

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
}