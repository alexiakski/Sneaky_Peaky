#include "stdafx.hpp"
#include "Inimigo.hpp"

Inimigo::Inimigo(float x, float y, int largura, int altura, int num_vidas, int nivel_maldade) 
        : Personagem(x, y, largura, altura, num_vidas), nivel_maldade(nivel_maldade)
{

}

Inimigo::~Inimigo()
{
    
}

int Inimigo::getNivelMaldade() const
{
    return nivel_maldade;
}
void Inimigo::setNivelMaldade(int nivel_maldade)
{
    this->nivel_maldade = nivel_maldade;
}

void Inimigo::colidir (Jogador *pJog)
{
    if(pJog != nullptr)
        danificar(pJog);
}

void Inimigo::danificar (Jogador* pJog)
{
    pJog->sofrerAtaque(nivel_maldade/2);
}

void Inimigo::salvarDataBuffer()
{
    //Implementar no requisito 10 #tomaraquedetempo
}

void Inimigo::mover()
{
    aplicarGravidade();
    
    if (pFig != nullptr)  
      pFig->setPosition(x, y);
}

void Inimigo::executar()
{
    mover();
}