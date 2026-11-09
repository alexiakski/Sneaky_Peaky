#include "Obstaculo.hpp"
#include "Jogador.hpp"

Obstaculo::Obstaculo(float x, float y, float largura, float altura, bool danoso) :
Entidade(x, y, largura, altura), danoso(danoso)
{

}
Obstaculo::~Obstaculo()
{

}

bool Obstaculo::getDanoso() const
{
    return danoso;
}
void Obstaculo::setDanoso(bool danoso)
{
    this->danoso = danoso;
}

void Obstaculo::salvarDataBuffer()
{

}

void Obstaculo::obstaculizar (Jogador *pJ)
{
    if(pJ == nullptr)
        return;

    if(danoso)
        pJ->setNumVidas(pJ->getNumVidas()-1);
    //else
        //pJ->reposicionar(getBounds());
}
