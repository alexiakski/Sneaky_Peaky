#include "stdafx.hpp"
#include "Inim_Bambu.hpp"

Inim_Facil::Inim_Facil(float x, float y) : Inimigo(x, y, 40, 40, 1, 1)//inimigo geral - bambu
{
    setTextura("assets/Idle.png", sf::IntRect(0, 0, 62, 62));//só a primeira posição
}

Inim_Facil::~Inim_Facil()
{

}

void Inim_Facil::danificar(Jogador* pJog)
{
    
}

void Inim_Facil::salvar()
{
    //Implementar no requisito 10 #tomaraquedetempo
}