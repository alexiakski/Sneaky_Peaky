#include "Entidade.hpp"

Entidade::Entidade(float x, float y, float largura, float altura) :
Ente(), x(x), y(y), largura(largura),altura(altura)
{
    if (pFig != nullptr) {
        pFig->setPosition(x, y);
        pFig->setSize(sf::Vector2f(largura, altura));
    }
}

Entidade::~Entidade()
{
    
}

float Entidade::getX() const
{
    return x;
}

float Entidade::getY() const
{
    return y;
}
float Entidade::getLargura() const
{
    return largura;
}
float Entidade::getAltura() const
{
    return altura;
}

sf::FloatRect Entidade::getBounds() const
{
    if (pFig != nullptr) {
        return pFig->getGlobalBounds();
    }
    return sf::FloatRect(x, y, largura, altura);
}

void Entidade::salvarDataBuffer()
{
    // implementar no requisito 10 (salvar jogada)  
}