#include "stdafx.hpp"
#include "Inim_Bambu.hpp"

Inim_Bambu::Inim_Bambu(float x, float y) : Inimigo(x, y, 40, 40, 1, 1)//inimigo geral - bambu
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