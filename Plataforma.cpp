#include "Plataforma.hpp"

Plataforma::Plataforma(int x, int y, int largura, int altura)
{

}
Plataforma::~Plataforma()
{

}

int Plataforma::getLargura()
{
    return largura;
}
int Plataforma::getAltura()
{
    return altura;
}

virtual void Plataforma::executar()
{
    aplicarFisica();
}
void Plataforma::salvarDataBuffer()
{

}
virtual void Plataforma::salvar()
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
            pJ->setVelocidadeY(-20);
}