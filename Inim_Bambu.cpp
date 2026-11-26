#include "stdafx.hpp"
#include "Inim_Bambu.hpp"

namespace Entidades::Personagens 
{

Inim_Bambu::Inim_Bambu(float x, float y) : Inimigo(x, y, 40, 40, 1, 1, 0.5f)
{
    setTextura("assets/Idle.png", sf::IntRect(0, 0, 62, 62));//só a primeira posição
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
    ofstream("save/inim_bambu.txt", ios::app) << buffer.str() << '\n';
}

void Inim_Bambu::executar()
{
    Inimigo::executar();
}
}