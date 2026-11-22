#include "stdafx.hpp"
#include "Inim_Bambu.hpp"

namespace Entidades::Personagens 
{

Inim_Bambu::Inim_Bambu(float x, float y) : Inimigo(x, y, 40, 40, 1, 1), contador(0), direcao(1)//inimigo geral - bambu
{
    setTextura("assets/Idle.png", sf::IntRect(0, 0, 62, 62));//só a primeira posição
}

Inim_Bambu::~Inim_Bambu()
{

}

void Inim_Bambu::danificar(Jogador* pJog)
{
    
}

void Inim_Bambu::salvar()
{
    //Implementar no requisito 10 #tomaraquedetempo
}

void Inim_Bambu::executar()
{
    x += 0.5f * direcao;
    contador++;

    if (contador >= 60)
    {
        direcao = -direcao;
        contador = -60;
    }

    Inimigo::executar();
}
}