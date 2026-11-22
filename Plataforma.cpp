#include "Plataforma.hpp"

using namespace Entidades::Personagens;
namespace Entidades::Obstaculos
{

Plataforma::Plataforma(float x, float y, float largura, float altura, float velocidadeY)
            :Obstaculo(x, y, largura, altura), velocidadeY(velocidadeY)
{
    if (pFig != nullptr)
        {
            pFig->setPosition(x, y);
            setTextura("assets/TilesetField.png", sf::IntRect(1, 48, 46, 46));//grama verde pra combinar com as duas fases
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

   if ( pJ->getVelocidadeY() > 0 &&//só segura quem está caindo (atravessa na subida)
         pJ->getX() + pJ->getLargura() >= x && pJ->getX() <= x + largura &&
         pJ->getY() + pJ->getAltura() >= y - 5 && pJ->getY() + pJ->getAltura() <= y + 12 )

        pJ->reposicionar(this->getBounds());
}
}