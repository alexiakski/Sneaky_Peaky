#include "stdafx.hpp"
#include "Inim_DuendeAzul.hpp"

namespace Entidades::Personagens 
{

Inim_DuendeAzul::Inim_DuendeAzul(float x, float y) : Inimigo(x, y, 60, 45, 2, 2)
{
    setTextura("assets/TenguAzul.png", sf::IntRect(0, 0, 68, 51));//só a primeira pose
}

Inim_DuendeAzul::~Inim_DuendeAzul()
{

}

void Inim_DuendeAzul::danificar(Jogador* pJog)
{

}

void Inim_DuendeAzul::salvar()
{

}

void Inim_DuendeAzul::executar()
{
    contador++;

    if (contador >= 180 && contador < 270)// 1,5s "fantasma" a cada 3s
    {
        invencivel = 2;//transparente = não leva dano
        if (pFig != nullptr)
            pFig->setFillColor(sf::Color(255, 255, 255, 80));//alfa = 80/255
    }
    else
    {
        if (pFig != nullptr)
            pFig->setFillColor(sf::Color(255, 255, 255, 255));

        if (contador >= 270)
            contador = 0;
    }

    Inimigo::executar();
}
}