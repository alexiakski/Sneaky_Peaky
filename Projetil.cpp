#include "Projetil.hpp"
#include "Personagem.hpp"
#include "Samurai.hpp"

using namespace Entidades::Personagens;

namespace Entidades 
{

Projetil::Projetil(float x, float y, float largura, float altura, int dano, float velocidade, Samurai* pAtirador)
        :Entidade(x, y, largura, altura), dano(dano), velocidade(velocidade), pAtirador(pAtirador)
{
    setTextura ("assets/Shuriken.png");
}

Projetil::~Projetil()
{
    pAtirador = nullptr;
}

Samurai* Projetil::getAtirador() const
{
    return pAtirador;
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
    buffer << dano << ' ' << velocidade << ' ' << (pAtirador != nullptr ? pAtirador->getId() : -1);
    ofstream("save/projetil.txt", ios::app) << buffer.str() << '\n';
}

}