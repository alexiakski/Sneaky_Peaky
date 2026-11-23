#include "Obst_Dificil.hpp"

using namespace Entidades::Personagens;

namespace Entidades::Obstaculos 
{
Obst_Dificil::Obst_Dificil(float x, float y, float largura, float altura, short int danosidade)
            :Obstaculo(x, y, largura, altura), danosidade(danosidade)
{
    if (pFig != nullptr)
        {
            pFig->setPosition(x, y);
            //setTextura("assets/TilesetNature.png", sf::IntRect(0, 0, 96, 48));//qual recorte?
        }
}

Obst_Dificil::~Obst_Dificil()
{

}

short int Obst_Dificil::getDanosidade() const
{
    return danosidade;
}
void Obst_Dificil::setDanosidade(short int danosidade)
{
    this->danosidade = danosidade;
}

void Obst_Dificil::executar() 
{
    if (pFig != nullptr)
    {
        pFig->setPosition(x, y);
    }
}
void Obst_Dificil::salvarDataBuffer()
{
    Obstaculo::salvarDataBuffer();
    buffer << danosidade << ' ';
}
void Obst_Dificil::salvar()
{
    salvarDataBuffer();
    ofstream("save/obst_dificil.txt", ios::app) << buffer.str() << '\n';
}
void Obst_Dificil::obstaculizar (Jogador *pJ)
{
    if (pJ == nullptr) 
        return;

    pJ->reposicionarJogObst(getBounds());
    *pJ -= danosidade;
}
}