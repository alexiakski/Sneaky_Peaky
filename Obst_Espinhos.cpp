#include "Obst_Espinhos.hpp"

using namespace Entidades::Personagens;

namespace Entidades::Obstaculos 
{
Obst_Espinhos::Obst_Espinhos(float x, float y, float largura, float altura, short int danosidade)
            :Obstaculo(x, y, largura, altura), danosidade(danosidade)
{
    if (pFig != nullptr)
        {
            pFig->setPosition(x, y);
            setTextura("assets/TilesetNature.png", sf::IntRect(64, 144, 16, 16));
        }
}

Obst_Espinhos::~Obst_Espinhos()
{

}

short int Obst_Espinhos::getDanosidade() const
{
    return danosidade;
}
void Obst_Espinhos::setDanosidade(short int danosidade)
{
    this->danosidade = danosidade;
}

void Obst_Espinhos::executar() 
{
    if (pFig != nullptr)
    {
        pFig->setPosition(x, y);
    }
}
void Obst_Espinhos::salvarDataBuffer()
{
    Obstaculo::salvarDataBuffer();
    buffer << danosidade << ' ';
}
void Obst_Espinhos::salvar()
{
    salvarDataBuffer();
    ofstream("save/obst_espinhos.txt", ios::app) << buffer.str() << '\n';
}
void Obst_Espinhos::obstaculizar (Jogador *pJ)
{
    if (pJ == nullptr) 
        return;

    pJ->reposicionarJogObst(getBounds());
    *pJ -= danosidade;
}
}