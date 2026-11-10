#include "Inimigo.hpp"
#include "Jogador.hpp"

Inimigo::Inimigo(float x, float y, float largura, float altura, int nivel_maldade) :
Personagem(x, y, largura, altura, 3), nivel_maldade(nivel_maldade)
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
void Inimigo::mover()
{

}

virtual void Inimigo::danificar (Jogador* pJog)
[
    pJog->sofrerAtaque(nivel_maldade/2);
]

void Inimigo::salvarDataBuffer()
{

}