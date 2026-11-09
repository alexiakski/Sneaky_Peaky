#include "stdafx.hpp"
#include "Jogo.hpp"
#include "Ente.hpp"
#include "Fase_one.hpp"

Jogo::Jogo() : GG(), pFase(nullptr) //jog1(100, 100, 48, 48, 1)//posicao (100,100) e tamanho (48,48) e jogador (1)
{
    Ente::setGG(&GG);//entes são conectados com gerenciador
    srand(time(nullptr));
    pFase = new Fase_one();
}

Jogo::~Jogo()
{
    delete pFase;
    pFase = nullptr;
}

void Jogo::executar()
{
    while (GG.estaAberta())//loop do jogo
    {
        GG.processarEventos();
        //jog1.executar();
        GG.limpar();
        pFase->executar();
        //jog1.desenhar();
        GG.mostrar();
    }
}