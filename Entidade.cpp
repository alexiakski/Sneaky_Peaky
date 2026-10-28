#include "Entidade.hpp"

Entidade::Entidade(float x, float y) : Ente(), x(x), y(y)
{
    pFig->setPosition(x, y);
}

Entidade::~Entidade()
{
    
}

float Entidade::getX()
{
    return x;
}

float Entidade::getY()
{
    return y;
}

void Entidade::salvarDataBuffer()
{
    // implementar no requisito 10 (salvar jogada)
}