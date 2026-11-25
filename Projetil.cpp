#include "Projetil.hpp"
#include "Personagem.hpp"

using namespace Entidades::Personagens;

namespace Entidades 
{

Projetil::Projetil(float x, float y, float largura, float altura, int dano, float velocidade)
        :Entidade(x, y, largura, altura), dano(dano), velocidade(velocidade)
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
        x += velocidade;

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
    if (!ativo)
        return;

    salvarDataBuffer();
    buffer << dano << ' ' << velocidade;
    ofstream("save/projetil.txt", ios::app) << buffer.str() << '\n';
}

}