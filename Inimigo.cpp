#include "stdafx.hpp"
#include "Inimigo.hpp"

namespace Entidades::Personagens 
{

Inimigo::Inimigo(float x, float y, int largura, int altura, int num_vidas, int nivel_maldade, float velocidadeX) 
        : Personagem(x, y, largura, altura, num_vidas),
        nivel_maldade(nivel_maldade), velocidadeX(velocidadeX), passos ((116 - largura) / velocidadeX / 2), direcao(1)
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

void Inimigo::setPatrulha(int passos, int direcao)
{
    this->passos = passos;
    this->direcao = direcao;
}

void Inimigo::colidir (Jogador *pJog)
{
    if(pJog != nullptr)
    {
        danificar(pJog);
        pJog->reposicionarJogInim(this->getBounds());
    }
}

void Inimigo::salvarDataBuffer()
{
    Personagem::salvarDataBuffer();
    buffer << nivel_maldade << ' '<< passos << ' ' << direcao << ' ';
}

void Inimigo::mover()
{
    x += velocidadeX * direcao;
    passos++;

    if (passos >= (116 - largura)/velocidadeX)
    {
        direcao = -direcao;
        passos = 0;
    }

    aplicarGravidade();

    if (pFig != nullptr)  
      pFig->setPosition(x, y);
}

void Inimigo::executar()
{
    atualizarInvincibilidade();
    mover();
}

}