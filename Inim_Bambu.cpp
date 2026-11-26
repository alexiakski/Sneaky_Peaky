#include "stdafx.hpp"
#include "Inim_Bambu.hpp"

namespace Entidades::Personagens 
{

Inim_Bambu::Inim_Bambu(float x, float y) : Inimigo(x, y, 37, 40, 1, 1, 0.5f), crescimento(0)
{
    setTextura("assets/Idle.png", sf::IntRect(7, 5, 48, 52));//só a parte visivel
}

Inim_Bambu::~Inim_Bambu()
{

}

void Inim_Bambu::danificar(Jogador* pJog)
{
    if (pJog != nullptr)
        pJog->sofrerAtaque(nivel_maldade);
}

void Inim_Bambu::salvar()
{
    salvarDataBuffer();
    buffer << crescimento;
    ofstream("save/inim_bambu.txt", ios::app) << buffer.str() << '\n';
}

void Inim_Bambu::executar()
{
    crescimento ++;

    if (crescimento >= 900 && nivel_maldade < 3)//a cada 15s fica mais forte
    {
        nivel_maldade++;
        crescimento = 0;
        x -= largura * 0.05f;
    }

    const float escalas[3] = {1.0f, 1.1f, 1.2f};//cresce 10% por nível

    if (pFig != nullptr)
    {
        pFig->setScale(escalas[nivel_maldade - 1], escalas[nivel_maldade - 1]);
    }

    Inimigo::executar();
}
}