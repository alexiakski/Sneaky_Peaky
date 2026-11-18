#include "Plataforma.hpp"

Plataforma::Plataforma(int x, int y, int largura, int altura, float velocidadeY):
Obstaculo(x, y, largura, altura), velocidadeY(velocidadeY)
{
if (pFig != nullptr)
    {
        pFig->setPosition(x, y);
    }
}
Plataforma::~Plataforma()
{

}

int Plataforma::getLargura() const
{
    return largura;
}
int Plataforma::getAltura() const
{
    return altura;
}

void Plataforma::executar()
{

}
void Plataforma::salvarDataBuffer()
{

}
void Plataforma::salvar()
{

}
void Plataforma::obstaculizar (Jogador *pJ)
{
    if (pJ == nullptr)
        return;

    else
        if ( pJ->getX() + pJ->getLargura() >= x && 
        pJ->getX() <= x + largura  && pJ->getY() + pJ->getAltura() >= y - 5 
        && pJ->getY() + pJ->getAltura() <= y + 5)
            //jogar o jogador para cima
            //pJ->setVelocidadeY(this-> velocidadeY - 20.0f);
            pJ->reposicionar(this->getBounds());
}
