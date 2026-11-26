#include "stdafx.hpp"
#include "Inim_DuendeAzul.hpp"

namespace Entidades::Personagens 
{

Inim_DuendeAzul::Inim_DuendeAzul(float x, float y) : Inimigo(x, y, 47, 29, 1, 2, 0.7f), contador (0), forcaAsas (2 + rand() % 3)
{
    setTextura("assets/TenguAzul.png", sf::IntRect(7, 18, 53, 33));//só a primeira pose
}

Inim_DuendeAzul::~Inim_DuendeAzul()
{

}

void Inim_DuendeAzul::danificar(Jogador* pJog)
{
    if (pJog != nullptr)
        pJog->sofrerAtaque(nivel_maldade);
}

void Inim_DuendeAzul::salvar()
{
    salvarDataBuffer();
    buffer << contador << ' ' << forcaAsas;
    ofstream("save/inim_duendeazul.txt", ios::app) << buffer.str() << '\n';
}

void Inim_DuendeAzul::executar()
{
    contador++;

    if (contador >= 180 && contador < 180 + forcaAsas * 30)// invisivel por 1 a 2s
    {
        invencivel = 2;//transparente = não leva dano
        if (pFig != nullptr)
            pFig->setFillColor(sf::Color(255, 255, 255, 80));//alfa = 80/255
    }
    else
    {
        if (pFig != nullptr)
            pFig->setFillColor(sf::Color(255, 255, 255, 255));

        if (contador >= 180 + forcaAsas * 30)
            contador = 0;
    }

    Inimigo::executar();
}
}