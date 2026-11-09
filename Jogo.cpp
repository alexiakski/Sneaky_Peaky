#include "stdafx.hpp"
#include "Jogo.hpp"
#include "Ente.hpp"
#include "Fase_one.hpp"

Jogo::Jogo() : GG(), menu(), pFase(nullptr)
{
    Ente::setGG(&GG);//entes são conectados com gerenciador
    srand(time(nullptr));
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
        GG.limpar();

        if (pFase == nullptr)//ainda no menu
        {
            menu.executar();

            if (menu.getFase() != 0)//escolheu uma fase
                pFase = new Fase_one();//fase 2: new Fase_two() quando existir
        }

        else
            pFase->executar();
        
        GG.mostrar();
    }
}