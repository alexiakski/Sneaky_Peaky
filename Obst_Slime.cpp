#include "Obst_Slime.hpp"

using namespace Entidades::Personagens;
namespace Entidades::Obstaculos 
{

Obst_Slime::Obst_Slime(float x, float y, float largura, float altura, float forca)
            :Obstaculo(x, y, largura, altura), forca(forca)
{
    if (pFig != nullptr)
    { 
        pFig->setPosition(x, y);
        setTextura("assets/TilesetNature.png", sf::IntRect(48, 256, 16, 16));
    }        
}

Obst_Slime::~Obst_Slime()
{

}

void Obst_Slime::executar() 
{
    if (pFig != nullptr)
        pFig->setPosition(x, y);
}

void Obst_Slime::salvar()
{
    salvarDataBuffer();
    buffer << forca;
    ofstream("save/obst_slime.txt", ios::app) << buffer.str() << '\n';
}
void Obst_Slime::obstaculizar (Jogador *pJ)
{
    /*if (pJ == nullptr)
        return;

    *pJ -= danosidade;
    pJ->reposicionar(this->getBounds());*/

    if (pJ == nullptr)
            return;

        float pesJog = pJ->getY() + pJ->getAltura();
        float centroJogX = pJ->getX() + pJ->getLargura() / 2.0f;

        if (pJ->getVelocidadeY() > 0 && pesJog <= y + 12)//caiu em cima: quica para cima
        {
            pJ->setPosicao(pJ->getX(), y - pJ->getAltura());
            pJ->setVelocidadeY(-forca);
        }
        else if (centroJogX < x)//encostou pela esquerda: volta para a esquerda
        {
            pJ->setPosicao(x - pJ->getLargura(), pJ->getY());
            pJ->setEmpurraoX(-forca / 2);
            pJ->setVelocidadeY(-forca / 2);
        }
        else if (centroJogX > x + largura)//encostou pela direita: volta para a direita
        {
            pJ->setPosicao(x + largura, pJ->getY());
            pJ->setEmpurraoX(forca / 2);
            pJ->setVelocidadeY(-forca / 2);
        }
}
}